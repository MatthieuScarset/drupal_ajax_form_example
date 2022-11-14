const path = require('path');
const MiniCssExtractPlugin = require("mini-css-extract-plugin");
const TerserPlugin = require("terser-webpack-plugin");

module.exports = {
  mode: 'production',
  stats: 'normal',
  entry: {
    "css/style": './scss/style.scss',
    "css/components": './scss/components.scss',
    "css/vertical-tabs": './scss/claro-libraries-extends/vertical-tabs.scss',
    "css/node-add": './scss/claro-libraries-extends/node-add.scss',
  },
  output: {
    filename: '[name].js',
    path: path.resolve(__dirname, 'assets/'),
    publicPath: "assets/"
  },
  module: {
    rules: [
      {
        test: /\.scss$/,
        use: [
          MiniCssExtractPlugin.loader,
          {
            loader: "css-loader",
            options: {
              url: false,
              importLoaders: 1
            }
          },
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
          {loader: 'sass-loader'},
          {loader: 'webpack-import-glob-loader'}
        ],
      },
    ],
  },
  optimization: {
    minimize: true,
    minimizer: [new TerserPlugin({test: /\.js(\?.*)?$/i})],
  },
  plugins: [
    new MiniCssExtractPlugin({
      filename: '[name].css'
    })
  ]
};
