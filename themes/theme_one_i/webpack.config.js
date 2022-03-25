const path= require('path');
const MiniCssExtractPlugin = require("mini-css-extract-plugin");
const CopyWebpackPlugin = require("copy-webpack-plugin");

module.exports = {
  mode: 'development',
  stats: 'normal',
  entry: {
    "css/one_i": './assets/scss/one_i.scss',
    "css/style": './assets/scss/style.scss'
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
  plugins: [
    new MiniCssExtractPlugin({
      filename: '[name].css'
    }),
    new CopyWebpackPlugin({
      patterns: [
        {from: './node_modules/@ob1/web/dist/js/ob1.*', to: 'js/[name][ext]'},
        {from: './node_modules/@ob1/web/dist/js/ob1.bundle.*', to: 'js/[name][ext]'},
        {from: './node_modules/boosted/dist/js/boosted.*', to: 'js/[name][ext]'},
        {from: './node_modules/boosted/dist/js/boosted.bundle.*', to: 'js/[name][ext]'},
        {from: './node_modules/@ob1/web/dist/fonts/icon-orange.json', to: 'fonts/[name][ext]'},
        {from: './node_modules/@ob1/web/dist/fonts/icon-orange.woff*', to: '../../../modules/custom/oab_icomoon/icon_orange/fonts/[name][ext]'},
        {from: './node_modules/@ob1/web/dist/css/orange-icons.css', to: '../../../modules/custom/oab_icomoon/icon_orange/css/[name][ext]'}
      ]
    })
  ]
};
