const path= require('path');
const MiniCssExtractPlugin= require("mini-css-extract-plugin");
module.exports= {
  mode: 'development',
  stats: 'normal',
  entry: {
    "one_i": './assets/scss/one_i.scss',
    "style": './assets/scss/style.scss',
  },
  output: {
    filename: '[name].js',
    path: path.resolve(__dirname, 'assets/css'),
    publicPath: "/assets/css"
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
    })
  ]
};
