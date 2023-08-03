const path = require('path');
const MiniCssExtractPlugin = require("mini-css-extract-plugin");

module.exports = {
  mode: 'production',
  stats: 'normal',
  entry: {
    "css/style": './assets/scss/style.scss',
  },
  output: {
    filename: '[name].js',
    path: path.resolve(__dirname, 'dist/'),
    publicPath: "/themes/theme_oab_hub_one_i/dist/"
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
        loader: 'file-loader',
        options: {
          name: 'fonts/[name].[ext]'
        }
      },
      {
        test: /\.js$/,
        exclude: /node_modules/,
        use: ["babel-loader"],
      },
    ],
  },
  plugins: [
    new MiniCssExtractPlugin({
      filename: '[name].css'
    })
  ],
  externals: {
    jquery: 'jQuery',
  },
  watchOptions: {
    poll: true,
    ignored: /node_modules/
  }
};
