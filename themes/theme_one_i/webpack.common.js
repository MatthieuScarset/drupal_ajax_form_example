const path = require('path');
const MiniCssExtractPlugin = require("mini-css-extract-plugin");
const MergeIntoSingleFilePlugin = require('webpack-merge-and-include-globally');
const {VueLoaderPlugin} = require("vue-loader");


module.exports = {
  stats: 'normal',
  entry: {
    "css/style": './assets/scss/style.scss',
    "js/script.min": "./assets/js/_mainScript.js",
    "js/modularContent.min": './assets/js/modular_content/main.js',
    "js/productFormule.min": './assets/js/product_formule/main.js',

    // Export Ytb-embed to be available with Theme Boosted without everything else that is in _mainScript
    "js/ytb-embed.min": "./assets/js/ytb-embed.main.js"
  },
  output: {
    filename: '[name].js',
    path: path.resolve(__dirname, 'dist/'),
    publicPath: "/themes/theme_one_i/dist/"
  },
  module: {
    rules: [
      {
        test: /\.scss$/,
        use: [
          MiniCssExtractPlugin.loader,
          "css-loader",
          {
            loader: 'postcss-loader',
            options: {
              postcssOptions: {
                plugins: [
                  ["autoprefixer"]
                ]
              }
            }
          },
          'resolve-url-loader',
          {loader: 'sass-loader', options: { sourceMap: true}},
          'webpack-import-glob-loader'
        ],
      },
      {
        test: /\.(woff2?|ttf|otf|eot|svg)$/,
        // exclude: /node_modules/,
        loader: 'file-loader',
        options: {
          name: 'fonts/[name].[ext]'
        }
      },
      {
        test: /\.tsx?$/,
        use: [{
          loader: 'ts-loader',
          options: {
            configFile: "tsconfig.json",
            appendTsSuffixTo: [/\.vue$/]
          }
        }],
        exclude: /node_modules/,
      },
      {
        test: /\.js$/,
        exclude: /node_modules/,
        use: ["babel-loader"],
      },
      {
        test: /\.vue$/,
        loader: 'vue-loader'
      },
    ],
  },
  plugins: [
    new VueLoaderPlugin(),
    /* Merge into one file all legacy JS files */
    new MergeIntoSingleFilePlugin({
      files: {
        "js/script-legacy.min.js": [
          "./assets/legacy_js/*.js"
        ]
      }
    }),
    new MiniCssExtractPlugin({
      filename: '[name].css'
    })
  ],
  externals: {
    jquery: 'jQuery',
  },
  resolve: {
    extensions: ['\*', '.js', '.jsx', '.vue'],
    symlinks: false,
    alias: {
      vue: 'vue/dist/vue.esm-browser'
    }
  },
  watchOptions: {
    poll: true,
    ignored: /node_modules/
  }
};
