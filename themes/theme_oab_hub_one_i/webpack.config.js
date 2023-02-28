const path = require('path')

const webpackConfig = require('../theme_one_i/webpack.common');

webpackConfig.mode = 'production';

webpackConfig.entry = {
  "css/style": './assets/scss/style.scss',
};

webpackConfig.output = {
  filename: '[name].js',
    path: path.resolve(__dirname, 'dist/'),
    publicPath: "/themes/theme_oab_hub_one_i/dist/"
}

module.exports = webpackConfig;
