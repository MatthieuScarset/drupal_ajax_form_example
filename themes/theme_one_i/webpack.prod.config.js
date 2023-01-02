
const TerserPlugin = require("terser-webpack-plugin");

// Default conf is for Dev
// Overrides config for prod
const webpackConfig = require('./webpack.common');

webpackConfig.mode = 'production';
webpackConfig.resolve.alias.vue = "vue/dist/vue.esm-browser.prod";

webpackConfig.optimization = {
  minimize: true,
  minimizer: [
    new TerserPlugin({
      test: /\.min.js(\?.*)?$/i,
      terserOptions: {
        keep_classnames: true,
        keep_fnames: true,
        format: {
          comments: false
        }
      },
      extractComments: false,
    })
  ],
};

module.exports = webpackConfig;

