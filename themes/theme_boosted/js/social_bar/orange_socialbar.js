var shares = {
    facebook: 0,
    twitter: 0,
    pinterest: 0,
    linkedin: 0,
    google: 0,
    user: 0
};
var svgIcons = {
    facebook: '<g><path fill="#ffffff" d="M19.368,9.987L21,9.986V7.125c-0.283-0.039-1.251-0.126-2.378-0.126c-2.352,0-3.962,1.491-3.962,4.23 v2.358H12v3.2h2.66v8.211h3.182v-8.211h2.652l0.397-3.2h-3.05v-2.042C17.842,10.619,18.089,9.987,19.368,9.987z"/></g>',
    twitter: '<g><path fill="#ffffff" d="M25,10.774c-0.662,0.302-1.374,0.505-2.121,0.597c0.762-0.469,1.348-1.211,1.623-2.096 c-0.713,0.435-1.504,0.75-2.345,0.919c-0.673-0.735-1.634-1.195-2.695-1.195c-2.04,0-3.693,1.695-3.693,3.787 c0,0.297,0.033,0.585,0.096,0.862c-3.069-0.158-5.791-1.665-7.612-3.956c-0.318,0.559-0.5,1.21-0.5,1.903 c0,1.313,0.652,2.473,1.643,3.152c-0.605-0.021-1.175-0.189-1.672-0.474c0,0.016,0,0.031,0,0.047 c0,1.835,1.273,3.366,2.962,3.714c-0.31,0.086-0.636,0.133-0.973,0.133c-0.238,0-0.469-0.024-0.695-0.068 c0.47,1.504,1.834,2.6,3.45,2.631c-1.264,1.015-2.856,1.62-4.586,1.62c-0.298,0-0.592-0.018-0.881-0.053 C8.634,23.373,10.575,24,12.661,24c6.792,0,10.507-5.771,10.507-10.775c0-0.164-0.004-0.327-0.011-0.489 C23.879,12.201,24.505,11.534,25,10.774z"/></g>',
/*    pinterest: '<g><path fill="#ffffff" d="M16.771,7.029c-4.933,0-7.421,3.537-7.421,6.488c0,1.786,0.676,3.375,2.126,3.968 c0.238,0.097,0.451,0.002,0.52-0.261c0.048-0.182,0.161-0.642,0.212-0.834c0.069-0.26,0.042-0.351-0.149-0.579 c-0.418-0.493-0.686-1.131-0.686-2.037c0-2.624,1.963-4.973,5.113-4.973c2.789,0,4.321,1.704,4.321,3.979 c0,2.994-1.325,5.522-3.292,5.522c-1.087,0-1.9-0.898-1.639-2.001c0.312-1.316,0.917-2.735,0.917-3.686 c0-0.85-0.457-1.559-1.401-1.559c-1.11,0-2.003,1.148-2.003,2.688c0,0.98,0.332,1.643,0.332,1.643s-1.136,4.815-1.335,5.659 c-0.397,1.68-0.061,3.739-0.032,3.946c0.017,0.123,0.175,0.152,0.247,0.06c0.102-0.134,1.425-1.767,1.875-3.398 c0.127-0.462,0.73-2.854,0.73-2.854c0.361,0.688,1.416,1.295,2.537,1.295c3.338,0,5.603-3.044,5.603-7.118 C23.346,9.897,20.737,7.029,16.771,7.029z"/></g>',*/
    linkedin: '<g><path fill="#ffffff" d="M9.922,7.999C8.859,7.999,8,8.862,8,9.925c0,1.063,0.859,1.927,1.922,1.927 c1.06,0,1.921-0.863,1.921-1.927C11.843,8.862,10.982,7.999,9.922,7.999z M8.263,24h3.317V13.312H8.263V24z M20.023,13.046 c-1.613,0-2.694,0.886-3.137,1.727h-0.045v-1.46H13.66V24h3.315v-5.287c0-1.395,0.264-2.745,1.988-2.745 c1.7,0,1.725,1.595,1.725,2.835V24h3.312v-5.862C23.999,15.259,23.379,13.046,20.023,13.046z"/></g>',
    googleplus: '<g><path fill="#ffffff" d="M15.462,17.227l-0.742-0.657c-0.107-0.115-0.218-0.25-0.332-0.404c-0.134-0.161-0.201-0.364-0.201-0.61 c0-0.254,0.065-0.477,0.196-0.669c0.111-0.185,0.231-0.35,0.362-0.496c0.229-0.215,0.443-0.427,0.646-0.634 c0.182-0.208,0.355-0.435,0.518-0.681c0.333-0.508,0.506-1.184,0.519-2.029c0-0.462-0.048-0.865-0.145-1.211 c-0.117-0.347-0.251-0.646-0.402-0.899c-0.158-0.27-0.32-0.496-0.485-0.681c-0.172-0.177-0.327-0.312-0.464-0.404h1.35 l1.352-0.852h-4.378c-0.581,0-1.203,0.073-1.867,0.219c-0.671,0.17-1.318,0.531-1.94,1.084c-0.906,0.945-1.359,1.999-1.359,3.16 c0,0.96,0.32,1.802,0.959,2.524c0.611,0.777,1.499,1.173,2.665,1.188c0.22,0,0.455-0.015,0.703-0.046 c-0.041,0.124-0.085,0.259-0.134,0.405c-0.055,0.14-0.082,0.313-0.082,0.521c0,0.349,0.072,0.646,0.216,0.894 c0.124,0.255,0.264,0.495,0.422,0.719c-0.511,0.016-1.152,0.084-1.925,0.207c-0.78,0.146-1.525,0.438-2.234,0.875 c-0.631,0.407-1.067,0.879-1.309,1.416c-0.248,0.537-0.373,1.024-0.373,1.462c0,0.897,0.382,1.67,1.145,2.313 c0.756,0.691,1.901,1.043,3.435,1.059c1.832-0.03,3.233-0.503,4.205-1.418c0.937-0.884,1.404-1.899,1.404-3.045 c-0.013-0.807-0.184-1.46-0.511-1.96C16.329,18.084,15.924,17.635,15.462,17.227z M12.727,14.53 c-0.456,0-0.862-0.149-1.216-0.451c-0.355-0.3-0.645-0.665-0.869-1.097c-0.464-0.925-0.695-1.815-0.695-2.67 c-0.014-0.646,0.145-1.231,0.476-1.757c0.393-0.5,0.887-0.758,1.48-0.773c0.448,0.016,0.845,0.157,1.19,0.428 c0.338,0.284,0.61,0.654,0.817,1.109c0.442,0.947,0.663,1.887,0.663,2.819c0,0.216-0.016,0.481-0.048,0.797 c-0.053,0.316-0.172,0.624-0.357,0.925C13.783,14.284,13.303,14.508,12.727,14.53z M14.984,23.271 c-0.543,0.478-1.331,0.723-2.363,0.738c-1.15-0.016-2.056-0.292-2.718-0.83c-0.697-0.538-1.045-1.224-1.045-2.054 c0-0.423,0.08-0.784,0.24-1.084c0.14-0.284,0.31-0.523,0.513-0.715C9.819,19.143,10.025,19,10.227,18.9 c0.202-0.093,0.359-0.162,0.47-0.208c0.474-0.153,0.938-0.265,1.391-0.334c0.46-0.046,0.746-0.062,0.857-0.046 c0.188,0,0.352,0.008,0.491,0.022c0.816,0.615,1.415,1.134,1.798,1.557c0.362,0.446,0.544,0.97,0.544,1.569 C15.779,22.199,15.514,22.802,14.984,23.271z"/><polygon fill="#ffffff" points="22,14.999 22,11.999 21,11.999 21,14.999 18,14.999 18,15.999 21,15.999 21,18.999 22,18.999 22,15.999 25,15.999 25,14.999"/></g>',
    email: '<g><path fill="#ffffff" d="M23.016,10H7.001L7,20.281c0,0.951,0.89,1.718,1.989,1.718H25c0,0,0-10.311,0-10.336 C25,10.713,24.115,10,23.016,10z M23.549,13.434l-5.471,4.71h-0.005c-0.538,0.477-1.268,0.721-2.071,0.721 c-0.803,0-1.533-0.244-2.072-0.721h-0.014l-5.472-4.707v-1.782c2.201,1.914,6.176,5.363,6.176,5.363h0.001 c0.355,0.303,0.84,0.467,1.374,0.467c0.565,0,1.074-0.207,1.436-0.554h0.002l6.115-5.302V13.434z"/></g>',
    sms: '<g><path fill="#ffffff" d="M10.518,25.981c0-1.275,0-2.472,0-3.707c-0.621,0-1.219,0-1.816,0c-0.586-0.006-1.083-0.226-1.388-0.717 c-0.175-0.282-0.316-0.643-0.322-0.965c-0.022-4.102-0.017-8.197-0.017-12.298c0-0.079,0.012-0.164,0.017-0.276 c0.113,0,0.214,0,0.316,0c5.28,0,10.567,0,15.847,0c1.155,0,1.872,0.722,1.872,1.89c0,4.006,0,8.005,0,12.011 c0,0.102,0,0.209,0,0.355c-0.117,0-0.231,0-0.339,0c-3.372,0-6.746,0-10.12-0.006c-0.214,0-0.367,0.062-0.513,0.214 c-1.111,1.111-2.228,2.213-3.339,3.317C10.67,25.845,10.619,25.885,10.518,25.981z M15.99,16.244c0.536,0,1.072,0,1.608,0 c1.06,0,2.127,0,3.188,0c0.411,0,0.739-0.232,0.874-0.593c0.134-0.367,0.056-0.801-0.271-1.015 c-0.221-0.142-0.519-0.232-0.784-0.232c-2.861-0.017-5.715-0.011-8.575-0.011c-0.271,0-0.547-0.006-0.818,0 c-0.423,0.017-0.745,0.197-0.902,0.604c-0.242,0.621,0.214,1.241,0.909,1.247C12.813,16.249,14.404,16.244,15.99,16.244z M15.99,10.822c-1.58,0-3.159,0-4.739,0c-0.592,0-0.999,0.373-1.004,0.908c0,0.531,0.417,0.914,0.998,0.914 c3.165,0,6.335,0,9.501,0c0.117,0,0.247-0.011,0.36-0.044c0.434-0.146,0.666-0.553,0.598-1.027 c-0.062-0.423-0.429-0.745-0.892-0.75C19.204,10.817,17.598,10.822,15.99,10.822z M13.553,17.993c-0.802,0-1.597-0.006-2.398,0 c-0.462,0.004-0.824,0.332-0.897,0.783c-0.062,0.413,0.186,0.853,0.581,0.987c0.165,0.057,0.35,0.073,0.525,0.073 c1.185,0.006,2.369,0.006,3.554,0.006c0.322,0,0.638,0.011,0.958-0.006c0.581-0.022,0.978-0.434,0.96-0.964 c-0.023-0.53-0.417-0.88-0.999-0.886C15.075,17.993,14.313,17.993,13.553,17.993z"/></g>',
    instagram: '<g><path fill="#FFFFFF" d="M10.694,7.029c0.069,0,0.139,0,0.209,0c0.1,0.026,0.126,0.096,0.126,0.187c0,0.026,0,0.057,0,0.083 c0,0.558-0.005,1.119-0.005,1.677c0,0.614,0,1.228-0.004,1.841c0,0.17-0.004,0.339,0.004,0.505c0.005,0.1,0.044,0.148,0.145,0.148 c0.139,0,0.278-0.008,0.418-0.018c0.078-0.008,0.13-0.056,0.143-0.139c0.01-0.052,0.018-0.104,0.018-0.157 c0.005-0.196,0.005-0.392,0.005-0.583c0-1.115,0-2.229,0-3.344c0-0.118,0-0.174,0.136-0.209c2.703,0,5.406,0,8.105,0 c0.018,0,0.039,0.004,0.057,0.004c0.483,0,0.967,0.004,1.445,0.004c0.244,0,0.487,0.026,0.723,0.083 c0.749,0.179,1.367,0.575,1.868,1.154c0.4,0.466,0.666,0.997,0.774,1.602c0.057,0.322,0.065,0.653,0.07,0.979 c0.004,0.636,0,1.276-0.005,1.911c0,0.101-0.026,0.126-0.126,0.126c-0.021,0-0.044,0-0.062,0c-1.775,0-3.548,0-5.324,0.004 c-0.117,0-0.209-0.035-0.296-0.113c-0.235-0.222-0.487-0.418-0.767-0.583c-0.988-0.592-2.05-0.801-3.183-0.592 c-0.883,0.161-1.649,0.566-2.307,1.175c-0.088,0.083-0.184,0.118-0.301,0.118c-1.785,0-3.57,0-5.354,0 c-0.108,0-0.136-0.026-0.136-0.135c0-0.161,0.005-0.322,0.005-0.479c-0.005-0.675-0.03-1.35,0.022-2.024 c0.029-0.409,0.125-0.806,0.295-1.176c0.262-0.566,0.666-1.01,1.154-1.384C8.557,7.69,8.565,7.686,8.573,7.682 c0,0.009,0,0.013,0,0.022c0,1.066,0,2.133-0.004,3.195c0,0.148-0.004,0.296,0.004,0.444c0.005,0.1,0.049,0.144,0.145,0.144 c0.135,0,0.27-0.004,0.4-0.022c0.087-0.008,0.131-0.061,0.144-0.152c0.009-0.056,0.013-0.113,0.013-0.17c0-1.206,0-2.412,0-3.613 c0-0.026,0-0.052-0.004-0.078c-0.018-0.122-0.009-0.135,0.1-0.188C9.479,7.212,9.588,7.168,9.706,7.16 c0.087-0.004,0.108,0.017,0.096,0.1C9.798,7.29,9.793,7.32,9.793,7.351c0,1.088,0,2.181,0,3.27c0,0.239,0,0.479,0,0.714 c0,0.1,0.039,0.148,0.14,0.148c0.13,0.004,0.256,0,0.387-0.009c0.117-0.009,0.17-0.061,0.188-0.183 c0.009-0.065,0.014-0.135,0.014-0.205c0.004-0.64,0.004-1.28,0.004-1.916c0-0.636-0.004-1.267-0.009-1.903 C10.524,7.094,10.542,7.072,10.694,7.029z M20.285,10.05L20.285,10.05c0,0.332-0.004,0.667,0,0.997 c0.009,0.322,0.235,0.54,0.562,0.54c0.627,0,1.258,0,1.886,0c0.335,0,0.569-0.231,0.569-0.566c0.005-0.645,0.005-1.289,0-1.933 c0-0.335-0.227-0.566-0.562-0.57c-0.636-0.004-1.267-0.004-1.902,0c-0.331,0.004-0.548,0.213-0.557,0.544 C20.276,9.388,20.285,9.719,20.285,10.05z"/><path fill="#FFFFFF" d="M12.274,13.438c-0.692,1.032-0.988,2.146-0.783,3.374c0.178,1.072,0.661,1.977,1.484,2.696 c1.65,1.432,4.018,1.527,5.751,0.221c0.984-0.739,1.576-1.728,1.768-2.942s-0.101-2.325-0.792-3.348c0.025,0,0.047,0,0.065,0 c1.479,0,2.965,0,4.444,0c0.166,0,0.326,0,0.492,0c0.03,0,0.061,0,0.096,0.004c0.074,0.008,0.117,0.047,0.126,0.122 c0.009,0.1,0.009,0.205,0.009,0.309c0,0.74-0.004,1.484-0.004,2.225c0,1.811,0,3.617-0.005,5.429 c-0.004,0.888-0.326,1.658-0.923,2.312c-0.526,0.575-1.176,0.94-1.946,1.08c-0.195,0.034-0.396,0.056-0.592,0.056 c-3.631,0.005-7.257,0.01-10.888,0c-1.643-0.004-3-1.092-3.393-2.655c-0.078-0.309-0.108-0.626-0.108-0.944 c0-1.689,0-3.374,0-5.063c0-0.862-0.005-1.729-0.005-2.591c0-0.039,0.005-0.078,0.005-0.113c0.013-0.109,0.057-0.157,0.17-0.161 c0.113-0.004,0.23-0.004,0.344-0.004c1.536,0,3.073,0.004,4.614,0.004C12.222,13.438,12.243,13.438,12.274,13.438z"/><path fill="#FFFFFF" d="M16.015,12.566c1.941,0,3.517,1.581,3.513,3.527c-0.005,1.95-1.571,3.513-3.535,3.508 c-1.946,0-3.518-1.575-3.518-3.522C12.475,14.143,14.063,12.566,16.015,12.566z M18.609,16.128c0.009-1.441-1.115-2.656-2.63-2.634 c-1.438,0.021-2.6,1.214-2.556,2.638c0.044,1.436,1.202,2.59,2.664,2.551C17.468,18.645,18.622,17.481,18.609,16.128z"/></g>',
/*    slideshare: '<g><path style=" " d="M 8 4 C 6.355469 4 5 5.355469 5 7 L 5 15.40625 C 4.230469 14.960938 3.628906 14.5625 3.5 14.5625 C 3.140625 14.5625 3 14.90625 3 15.125 C 3 16.246094 6.335938 18.40625 8.4375 19.1875 C 8.4375 19.1875 7.90625 20.738281 7.90625 22.5 C 7.90625 24.261719 8.992188 28 12.4375 28 C 12.4375 28 15 27.992188 15 25.46875 L 15 20.5 L 17 21.09375 L 17 25.46875 C 17 27.992188 19.5625 28 19.5625 28 C 23.007813 28 24.09375 24.261719 24.09375 22.5 C 24.09375 20.738281 23.5625 19.1875 23.5625 19.1875 C 25.664063 18.40625 29 16.246094 29 15.125 C 29 14.90625 28.859375 14.5625 28.5 14.5625 C 28.371094 14.5625 27.769531 14.960938 27 15.40625 L 27 7 C 27 5.355469 25.644531 4 24 4 Z M 8 6 L 24 6 C 24.566406 6 25 6.433594 25 7 L 25 16.40625 C 23.886719 16.871094 22.601563 17.25 21.28125 17.25 C 19.820313 17.25 18.902344 17.15625 18.28125 17.15625 C 17.078125 17.15625 17 18.4375 17 18.4375 L 17 19.34375 L 14.65625 17.5625 C 14.46875 17.339844 14.167969 17.15625 13.71875 17.15625 C 13.097656 17.15625 12.179688 17.25 10.71875 17.25 C 9.398438 17.25 8.113281 16.871094 7 16.40625 L 7 7 C 7 6.433594 7.433594 6 8 6 Z M 12.3125 10.96875 C 10.835938 10.96875 9.65625 12.113281 9.65625 13.5 C 9.65625 14.886719 10.835938 16 12.3125 16 C 13.789063 16 15 14.886719 15 13.5 C 15 12.113281 13.789063 10.96875 12.3125 10.96875 Z M 19.6875 10.96875 C 18.210938 10.96875 17 12.113281 17 13.5 C 17 14.886719 18.210938 16 19.6875 16 C 21.164063 16 22.34375 14.886719 22.34375 13.5 C 22.34375 12.113281 21.164063 10.96875 19.6875 10.96875 Z "></path></g>',*/
    newsletter: '<g><path fill="#ffffff" d="M23.016,10H7.001L7,20.281c0,0.951,0.89,1.718,1.989,1.718H25c0,0,0-10.311,0-10.336 C25,10.713,24.115,10,23.016,10z M23.549,13.434l-5.471,4.71h-0.005c-0.538,0.477-1.268,0.721-2.071,0.721 c-0.803,0-1.533-0.244-2.072-0.721h-0.014l-5.472-4.707v-1.782c2.201,1.914,6.176,5.363,6.176,5.363h0.001 c0.355,0.303,0.84,0.467,1.374,0.467c0.565,0,1.074-0.207,1.436-0.554h0.002l6.115-5.302V13.434z"/></g>',
    youtube: '<g><path fill="#FFFFFF" d="M26.165,12.718c0,0-0.19-1.344-0.775-1.935c-0.74-0.777-1.572-0.781-1.951-0.826 c-2.729-0.197-6.82-0.197-6.82-0.197h-0.007c0,0-4.092,0-6.82,0.197c-0.38,0.045-1.212,0.049-1.953,0.826 c-0.584,0.591-0.774,1.935-0.774,1.935S6.87,14.293,6.87,15.872v1.479c0,1.578,0.195,3.154,0.195,3.154s0.19,1.343,0.774,1.935 c0.743,0.777,1.716,0.752,2.148,0.834c1.559,0.148,6.626,0.196,6.626,0.196s4.095-0.007,6.824-0.204 c0.382-0.045,1.211-0.049,1.952-0.827c0.584-0.591,0.775-1.935,0.775-1.935s0.194-1.577,0.194-3.153v-1.48 C26.359,14.293,26.165,12.718,26.165,12.718z M14.602,19.142v-5.476l5.266,2.748L14.602,19.142z"/></g>',
/*    dailymotion: '<g><path fill="#FFFFFF" d="M19.109,13.341c0.002-0.067,0.002-0.109,0.002-0.152c0-1.757,0-3.511,0-5.269c0-0.042,0-0.084,0.003-0.129 c0.003-0.062,0.017-0.082,0.079-0.095c0.115-0.025,0.229-0.047,0.342-0.072c0.396-0.082,0.793-0.164,1.187-0.247 c0.468-0.097,0.937-0.194,1.403-0.292c0.246-0.052,0.496-0.102,0.742-0.152c0.029-0.004,0.061-0.007,0.098-0.012 c0.01,0.03,0.02,0.055,0.021,0.08c0.006,0.042,0.003,0.084,0.003,0.127c0,5.891,0,11.78,0,17.671c0,0.062,0.007,0.125-0.018,0.189 c-0.024,0.006-0.05,0.015-0.077,0.018c-0.035,0.003-0.07,0.003-0.105,0.003c-1.121,0-2.242,0-3.363,0 c-0.058,0-0.117,0.007-0.18-0.022c-0.005-0.028-0.016-0.058-0.016-0.088c-0.002-0.074-0.002-0.146-0.002-0.222 c0-0.316,0-0.631,0-0.947c0-0.037-0.002-0.074-0.006-0.109c-0.036-0.015-0.049,0.013-0.066,0.024 c-0.145,0.125-0.286,0.252-0.436,0.372c-0.568,0.448-1.201,0.757-1.91,0.914c-0.234,0.053-0.474,0.091-0.712,0.113 c-0.242,0.021-0.481,0.037-0.723,0.034c-0.217,0-0.437-0.015-0.653-0.034c-0.339-0.03-0.671-0.091-0.998-0.178 c-0.937-0.249-1.754-0.715-2.469-1.363c-0.417-0.379-0.79-0.795-1.106-1.261c-0.414-0.608-0.713-1.267-0.902-1.977 c-0.075-0.281-0.129-0.567-0.17-0.856c-0.062-0.437-0.077-0.875-0.062-1.316c0.01-0.267,0.042-0.533,0.085-0.8 c0.062-0.394,0.162-0.775,0.296-1.151c0.256-0.718,0.631-1.371,1.114-1.959c0.484-0.588,1.035-1.102,1.678-1.51 c0.648-0.412,1.348-0.693,2.103-0.83c0.244-0.044,0.491-0.075,0.74-0.094c0.217-0.018,0.436-0.022,0.653-0.013 c0.519,0.02,1.029,0.095,1.522,0.265c0.709,0.242,1.307,0.65,1.795,1.216C19.031,13.254,19.062,13.286,19.109,13.341z M19.256,18.436c0-0.182-0.005-0.367-0.035-0.547c-0.059-0.363-0.166-0.71-0.336-1.038c-0.523-1.01-1.537-1.638-2.657-1.668 c-0.257-0.007-0.514,0.003-0.765,0.055c-0.827,0.177-1.493,0.608-1.984,1.298c-0.396,0.556-0.583,1.181-0.59,1.862 c-0.002,0.172,0.018,0.341,0.042,0.51c0.057,0.389,0.185,0.756,0.386,1.095c0.436,0.729,1.077,1.196,1.887,1.431 c0.231,0.066,0.468,0.104,0.71,0.127c0.344,0.032,0.686,0.015,1.02-0.067c0.732-0.18,1.318-0.583,1.752-1.202 C19.076,19.733,19.262,19.113,19.256,18.436z"/></g>'*/
};

var staticText = {
    en_US:
    {
        shares: 'shares',
        share: 'share',
        toshare: 'Share',
        follow: 'Follow us',
        to: 'To',
        from: 'From',
        subject: 'Subject',
        message: 'Message',
        email: 'email address',
        optional: 'optional',
        cancel: 'cancel',
        send: 'send',
        more: 'More options',
        accessibility: {
            shareon: 'Share on',
            sharewith: 'Share with',
            follow: 'Follow us on',
            newsletter: 'Subscribe to our newsletter'
        }
    },
    fr_FR:
    {
        shares: 'partages',
        share: 'partage',
        toshare: 'Partager',
        follow: 'Suivez-nous',
        to: 'À',
        from: 'De',
        subject: 'Sujet',
        message: 'Message',
        email: 'adresse courriel',
        optional: 'facultatif',
        cancel: 'annuler',
        send: 'envoyer',
        more: 'Plus d\'options',
        accessibility: {
            shareon: 'Partager sur',
            sharewith: 'Partager par',
            follow: 'Suivez-nous sur',
            newsletter: 'Abonnez-vous à notre newsletter'
        }
    },
    es_ES:
    {
        shares: 'veces compartido',
        share: 'vez compartida',
        toshare: 'Compartir',
        follow: 'Síguenos',
        to: 'Para',
        from: 'Desde',
        subject: 'Asunto',
        message: 'Mensaje',
        email: 'correo electrónico',
        optional: 'opcional',
        cancel: 'Cancelar',
        send: 'Enviar',
        more: 'Más opciones',
        accessibility: {
            shareon: 'Compartir en',
            sharewith: 'Compartir por',
            follow: 'síguenos en',
            newsletter: 'Suscribirse a la Newsletter'
        }
    },
    pl_PL:
    {
        shares: 'ponowne udostępnienia',
        share: 'udostępnienie',
        toshare: 'Udostępnij',
        follow: 'zobacz nas',
        to: 'do',
        from: 'z',
        subject: 'przedmiot',
        message: 'wiadomość',
        email: 'adres e-mail',
        optional: 'fakultatywny',
        cancel: 'anulować',
        send: 'wysłać',
        more: 'Więcej opcji',
        accessibility: {
            shareon: 'podziel się',
            sharewith: 'wyślij na',
            follow: 'Zobacz nas',
            newsletter: 'Zapisz się do newslettera'
        }
    },
    ro_RO:
    {
        shares: 'distribuiri',
        share: 'distribuire',
        toshare: 'Distribuie',
        follow: 'ne găsim',
        to: 'pentru',
        from: 'de la',
        subject: 'subiect',
        message: 'mesaj',
        email: 'adresa de e-mail',
        optional: 'facultativ',
        cancel: 'anula',
        send: 'trimite',
        more: 'Mai multe opțiuni',
        accessibility: {
            shareon: 'Trimite pe',
            sharewith: 'Trimite prin',
            follow: 'Urmareste-ne si pe',
            newsletter: 'abonează-te la newsletter'
        }
    },
    ar_AR:
    {
        shares: 'مشاركة',
        share: 'مشاركة واحدة',
        toshare: 'مشاركة',
        follow: 'تابعنا',
        to: 'إلى',
        from: 'من',
        subject: 'موضوع',
        message: 'رسالة',
        email: 'عنوان البريد الإلكتروني',
        optional: 'اختياري',
        cancel: 'إلغاء',
        send: 'إرسال',
        more: 'خيارات أكثر',
        accessibility: {
            shareon: 'مشاركة على',
            sharewith: 'من خلال تبادل',
            follow: 'تتبعوا أخبارنا',
            newsletter: 'رسالة إخبارية'
        }
    },
    ru_RU:
        {
            shares: 'shares',
            share: 'share',
            toshare: 'Share',
            follow: 'Присоединяйтесь к нам',
            to: 'To',
            from: 'From',
            subject: 'Subject',
            message: 'Message',
            email: 'email address',
            optional: 'optional',
            cancel: 'cancel',
            send: 'send',
            more: 'More options',
            accessibility: {
                shareon: 'Поделиться нa',
                sharewith: 'Share with',
                follow: 'Follow us on',
                newsletter: 'Subscribe to our newsletter'
            }
        }
    // (sharebar/followbar) add new language
    // xy_XY:
    // {
    //  shares: '',
    //  share: '',
    //  toshare: '',
    //  follow: '',
    //  to: '',
    //  from: '',
    //  subject: '',
    //  message: '',
    //  email: '',
    //  optional: '',
    //  cancel: '',
    //  send: '',
    //  more: '',
    //  accessibility: {
    //      shareon: '',
    //      sharewith: '',
    //      follow: ''
    //      newsletter: ''
    //  }
    // }
};

//check language
var currentLang = jQuery('html').attr('lang');
var staticTextLocale = '';
if(typeof currentLang !== "undefined" && currentLang !== null){
    if(currentLang === "en"){
         staticTextLocale = staticText.en_US;
    }else if(currentLang === "fr"){
         staticTextLocale = staticText.fr_FR;
    }else if(currentLang === "ru"){
         staticTextLocale = staticText.ru_RU;
    // (sharebar) add new language
    // }else if(sharebar_parameters.og_locale === "xy_XY"){
    //  var staticTextLocale = staticText.xy_XY;
    }else{
         staticTextLocale = staticText.en_US;
    }
}
/*}else if(typeof followbar_parameters !== "undefined"){
    if(typeof followbar_parameters.locale !== "undefined" && followbar_parameters.locale !== null){
        if(followbar_parameters.locale === "en_US"){
            var staticTextLocale = staticText.en_US;
        }else if(followbar_parameters.locale === "fr_FR"){
            var staticTextLocale = staticText.fr_FR;
        }else if(followbar_parameters.locale === "es_ES"){
            var staticTextLocale = staticText.es_ES;
        }else if(followbar_parameters.locale === "pl_PL"){
            var staticTextLocale = staticText.pl_PL;
        }else if(followbar_parameters.locale === "ro_RO"){
            var staticTextLocale = staticText.ro_RO;
        }else if(followbar_parameters.locale === "ar_AR"){
            var staticTextLocale = staticText.ar_AR;
        // (followbar) add new language
        // }else if(followbar_parameters.og_locale === "xy_XY"){
        //  var staticTextLocale = staticText.xy_XY;
        }else{
            var staticTextLocale = staticText.en_US;
        }
    }
}else{
    var staticTextLocale = staticText.en_US;
}*/

var checkIfRightToLeft = function(){
    var followBars = '';
    if(typeof sharebar_parameters !== "undefined"){
        if(typeof sharebar_parameters.og_locale !== "undefined" && sharebar_parameters.og_locale !== null){
            if(sharebar_parameters.og_locale === "ar_AR"){
                if(document.getElementById('sharebar')){
                    document.getElementById('sharebar').className += " righttoleft";
                }
                if(document.getElementsByClassName('followbar')){
                    followBars = document.getElementsByClassName('followbar');
                    for(var i=0;i<followBars.length;i++) {
                        followBars[i].className += " righttoleft";
                    }
                }
            }
        }
    }else if(typeof followbar_parameters !== "undefined"){
        if(typeof followbar_parameters.locale !== "undefined" && followbar_parameters.locale !== null){
            if(followbar_parameters.locale === "ar_AR"){
                if(document.getElementById('sharebar')){
                    document.getElementById('sharebar').className += " righttoleft";
                }
                if(document.getElementsByClassName('followbar')){
                    followBars = document.getElementsByClassName('followbar');
                    for(var i=0;i<followBars.length;i++) {
                        followBars[i].className += " righttoleft";
                    }
                }
            }
        }
    }
};

var setTotalSharesCount = function(){
    var total = shares.facebook + shares.twitter + shares.pinterest + shares.linkedin + shares.google + shares.user;
    if(sharebar_parameters.show_counter){
        if(total > 100000){
            document.getElementById('counter').innerHTML = "100K+";
        }else if(total <= 0){
            document.getElementById('counter').innerHTML = "";
        }else{
            document.getElementById('counter').innerHTML = total;
        }
    }
};

//Get share count of each social network for given url
var getFacebookShare = function(){
    $.ajax({
        type : "GET",
        dataType : "jsonp",
        url : "https://graph.facebook.com/?id=" + sharebar_parameters.og_url,
        success: function(data){
            if(!data.shares || data.shares === ""){
                data.shares = 0;
            }
            shares.facebook = data.shares;
            if(!sharebar_parameters.show_counter){
                document.getElementById('counterlabel').className='nocounter';
            }else{
                setTotalSharesCount();
            }
        //getShares();
        }
    });
};

var getTwitterShare = function(){
    // twitter disabled this url
    // $.ajax({
    //     type : "GET",
    //     dataType : "jsonp",
    //     url : "http://urls.api.twitter.com/1/urls/count.json?url=" + sharebar_parameters.og_url,
    //     success: function(data){
    //         if(!data || data === ""){
    //             data = 0;
    //         }
    //         shares.twitter = data.count;
    //     },
    //     error: function(data){
    //         setTotalSharesCount();
    //     }
    // });

    if(checkCookie('share_twitter')) {
        shares.twitter = 1;
    } else {
        shares.twitter = 0;
    }
};

var getPinterestShare = function(){
    $.ajax({
        type : "GET",
        dataType : "jsonp",
        url : "https://api.pinterest.com/v1/urls/count.json?callback=receiveCount&url=" + sharebar_parameters.og_url,
        success: function(data){}
    });
};

//callback function
var receiveCount = function(data){
    if(!data.count || data.count === ""){
        data.count = 0;
    }
    shares.pinterest = data.count;
    setTotalSharesCount();
};

var getLinkedinShare = function(){
    $.ajax({
        type : "GET",
        dataType : "json",
        url : "https://www.linkedin.com/countserv/count/share?url=" + sharebar_parameters.og_url,
        success: function(data){
            if(!data.count || data.count === ""){
                data.count = 0;
            }
            shares.linkedin = data.count;
            setTotalSharesCount();
        }
    });
};

//Get shortened URL
var getShortUrl = function(url){
    if(sharebar_parameters.use_bitly === true){
        var bitlyRequestUrl = "https://api-ssl.bitly.com/v3/shorten?access_token=" + sharebar_parameters.bitly_token + "&longUrl=" + url + "&format=txt";
        var xmlHttp = null;
        xmlHttp = new XMLHttpRequest();
        xmlHttp.open( "GET", bitlyRequestUrl, false);
        xmlHttp.send( null );
        return xmlHttp.responseText;
    }else{
        return url;
    }
};

//set share links
if(typeof sharebar_parameters !== "undefined" && typeof drupalSettings.shareSettings !== "undefined") {
    var via = sharebar_parameters.twitter_site.substring(1, sharebar_parameters.twitter_site.length);
    var share_links = {
        facebook: drupalSettings.shareSettings.share_siteUrls.facebook,
        twitter: drupalSettings.shareSettings.share_siteUrls.twitter,
        twitter_short: drupalSettings.shareSettings.share_siteUrls.twitter,
        googleplus: "https://plus.google.com/share?url=" + drupalSettings.shareSettings.og_url + "&hl=" + drupalSettings.shareSettings.og_locale.substring(0,2),
        linkedin: drupalSettings.shareSettings.share_siteUrls.linkedin,
        pinterest: "https://pinterest.com/pin/create/button/?url=" + drupalSettings.shareSettings.og_url + "&media=" + drupalSettings.shareSettings.og_image + "&description=" + drupalSettings.shareSettings.og_title
    };
}

//open the share popup
var shareClick = function(button){

    var config = "toolbar = no, location = no, directories = no, menubar = no, width = 560, height = 500";
    var link;
    var popup_title;
    if(button === 'facebook'){
        link = drupalSettings.shareSettings.share_siteUrls.facebook;
        popup_title = "Facebook share";
        window.open(link, popup_title, config);
    }else if(button === 'twitter' && sharebar_parameters.use_bitly === true){
        link = share_links.twitter_short;
        popup_title = "Twitter share";
        window.open(link, popup_title, config);
    }else if(button === 'twitter'){
        link = drupalSettings.shareSettings.share_siteUrls.twitter;
        popup_title = "Twitter share";
        window.open(link, popup_title, config);
    }else if(button === 'googleplus'){
        link = share_links.googleplus;
        popup_title = "Google Plus share";
        window.open(link, popup_title, config);
    }else if(button === 'linkedin'){
        link = drupalSettings.shareSettings.share_siteUrls.linkedin;
        popup_title = "LinkedIn share";
        window.open(link, popup_title, config);
        //shares.user += 1;
    }else if(button === 'pinterest'){
         link = share_links.pinterest;
         popup_title = "Pinterest share";
        window.open(link, popup_title, config);
        //shares.user += 1;
    }else if(button === 'email'){
        openMail();
    }else if(button === 'sms'){
        openSMS(sharebar_parameters.sms_text);
    }
};

var setCounterText = function(sharebarHTML){
    var total = shares.facebook + shares.twitter + shares.pinterest + shares.linkedin + shares.google + shares.user;
    if(total <= 0){
        sharebarHTML += '<p >' + staticTextLocale.toshare + '</p></div>';
    }else if(total == 1){
        sharebarHTML += '<p >' + staticTextLocale.share + '</p></div>';
    }else{
        sharebarHTML += '<p >' + staticTextLocale.shares + '</p></div>';
    }
};


var showShareBar = function(){

    var sharebarHTML = '<div id="counterlabel">';
    sharebarHTML += sharebar_parameters.show_counter ? '<p id="counter">0</p>' : "";

    var total = shares.facebook + shares.twitter + shares.pinterest + shares.linkedin + shares.google + shares.user;
    if(total <= 0){
        sharebarHTML += '<p id="countertext">' + staticTextLocale.toshare + '</p></div>';
    }else if(total == 1){
        sharebarHTML += '<p id="countertext">' + staticTextLocale.share + '</p></div>';
    }else{
        sharebarHTML += '<p id="countertext">' + staticTextLocale.shares + '</p></div>';
    }

    sharebarHTML += "<div class=\"content\">";

    for(var i=0, len=visible_sharebar_buttons.length;i<len;i++){
        var currentButton = visible_sharebar_buttons[i].button;

        if(visible_sharebar_buttons[i].button === 'email'){
            if(visible_sharebar_buttons[i].mailto === false){
                if( /Android|webOS|iPhone|iPad|iPod|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent) ) {
	        		if(sharebar_parameters.og_locale == "ar_AR"){
	        			sharebarHTML += "<a onmousedown=\"utag_link(utag_data.titre_page, 'Barre de partage', 'Partager', '"+ currentButton +"');\" href=\"mailto:?subject=" + sharebar_parameters.email_subject + "&cc=&bcc=&body=" + sharebar_parameters.email_message + "\" onclick=\"setCookie('share_" + currentButton + "', '" + window.location.pathname + "', 7300);\" class=\"share_" + currentButton + "\" id=\"share_" + currentButton + "\"><span class=\"sr-only\">email " + staticTextLocale.accessibility.sharewith + "</span><svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" x=\"0px\" y=\"0px\" width=\"32px\" height=\"32px\" viewBox=\"0 0 32 32\" enable-background=\"new 0 0 32 32\" xml:space=\"preserve\">" + svgIcons.email + "</svg></a>";
	        		}else{
	        			sharebarHTML += "<a onmousedown=\"utag_link(utag_data.titre_page, 'Barre de partage', 'Partager', '"+ currentButton +"');\" href=\"mailto:?subject=" + sharebar_parameters.email_subject + "&cc=&bcc=&body=" + sharebar_parameters.email_message + "\" onclick=\"setCookie('share_" + currentButton + "', '" + window.location.pathname + "', 7300);\" class=\"share_" + currentButton + "\" id=\"share_" + currentButton + "\"><span class=\"sr-only\">" + staticTextLocale.accessibility.sharewith + " email</span><svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" x=\"0px\" y=\"0px\" width=\"32px\" height=\"32px\" viewBox=\"0 0 32 32\" enable-background=\"new 0 0 32 32\" xml:space=\"preserve\">" + svgIcons.email + "</svg></a>";
	        		}
                }else{
	        		if(sharebar_parameters.og_locale == "ar_AR"){
                    sharebarHTML += "<a onmousedown=\"utag_link(utag_data.titre_page, 'Barre de partage', 'Partager', '"+ currentButton +"');\" href=\"javascript:void(0)\" onclick=\"setCookie('share_" + currentButton + "', '" + window.location.pathname + "', 7300);shareClick('" + currentButton + "');\" class=\"share_" + currentButton + "\" id=\"share_" + currentButton + "\"><span class=\"sr-only\">email " + staticTextLocale.accessibility.sharewith + "</span><svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" x=\"0px\" y=\"0px\" width=\"32px\" height=\"32px\" viewBox=\"0 0 32 32\" enable-background=\"new 0 0 32 32\" xml:space=\"preserve\">" + svgIcons.email + "</svg></a>";
	        		}else{
                    sharebarHTML += "<a onmousedown=\"utag_link(utag_data.titre_page, 'Barre de partage', 'Partager', '"+ currentButton +"');\" href=\"javascript:void(0)\" onclick=\"setCookie('share_" + currentButton + "', '" + window.location.pathname + "', 7300);shareClick('" + currentButton + "');\" class=\"share_" + currentButton + "\" id=\"share_" + currentButton + "\"><span class=\"sr-only\">" + staticTextLocale.accessibility.sharewith + " email</span><svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" x=\"0px\" y=\"0px\" width=\"32px\" height=\"32px\" viewBox=\"0 0 32 32\" enable-background=\"new 0 0 32 32\" xml:space=\"preserve\">" + svgIcons.email + "</svg></a>";
	        		}
                    sharebarHTML += "<span id=\"contentmail\"></span><span></span>";
                }
            }else{
	        	if(sharebar_parameters.og_locale == "ar_AR"){
                	sharebarHTML += "<a onmousedown=\"utag_link(utag_data.titre_page, 'Barre de partage', 'Partager', '"+ currentButton +"');\" href=\"mailto:?subject=" + sharebar_parameters.email_subject + "&cc=&bcc=&body=" + sharebar_parameters.email_message + "\" onclick=\"setCookie('share_" + currentButton + "', '" + window.location.pathname + "', 7300);\" class=\"share_" + currentButton + "\" id=\"share_" + currentButton + "\"><span class=\"sr-only\">email " + staticTextLocale.accessibility.sharewith + "</span><svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" x=\"0px\" y=\"0px\" width=\"32px\" height=\"32px\" viewBox=\"0 0 32 32\" enable-background=\"new 0 0 32 32\" xml:space=\"preserve\">" + svgIcons.email + "</svg></a>";
            	}else{
            		sharebarHTML += "<a onmousedown=\"utag_link(utag_data.titre_page, 'Barre de partage', 'Partager', '"+ currentButton +"');\" href=\"mailto:?subject=" + sharebar_parameters.email_subject + "&cc=&bcc=&body=" + sharebar_parameters.email_message + "\" onclick=\"setCookie('share_" + currentButton + "', '" + window.location.pathname + "', 7300);\" class=\"share_" + currentButton + "\" id=\"share_" + currentButton + "\"><span class=\"sr-only\">" + staticTextLocale.accessibility.sharewith + " email</span><svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" x=\"0px\" y=\"0px\" width=\"32px\" height=\"32px\" viewBox=\"0 0 32 32\" enable-background=\"new 0 0 32 32\" xml:space=\"preserve\">" + svgIcons.email + "</svg></a>";
            	}
            }
        }else if(visible_sharebar_buttons[i].button === 'sms'){
	        if(getDeviceAndVersion().os == "iOS" && getDeviceAndVersion().version != 7){
	        	if(sharebar_parameters.og_locale == "ar_AR"){
					sharebarHTML += "<a onmousedown=\"utag_link(utag_data.titre_page, 'Barre de partage', 'Partager', '"+ currentButton +"');\" href=\"javascript:void(0)\" onclick=\"setCookie('share_" + currentButton + "', '" + window.location.pathname + "', 7300);shareClick('" + currentButton + "');\" class=\"share_" + currentButton + "\" id=\"share_" + currentButton + "\"><span class=\"sr-only\">SMS " + staticTextLocale.accessibility.sharewith + "</span><svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" x=\"0px\" y=\"0px\" width=\"32px\" height=\"32px\" viewBox=\"0 0 32 32\" enable-background=\"new 0 0 32 32\" xml:space=\"preserve\">" + svgIcons.sms + "</svg></a>";
	        	}else{
		            sharebarHTML += "<a onmousedown=\"utag_link(utag_data.titre_page, 'Barre de partage', 'Partager', '"+ currentButton +"');\" href=\"javascript:void(0)\" onclick=\"setCookie('share_" + currentButton + "', '" + window.location.pathname + "', 7300);shareClick('" + currentButton + "');\" class=\"share_" + currentButton + "\" id=\"share_" + currentButton + "\"><span class=\"sr-only\">" + staticTextLocale.accessibility.sharewith + " SMS</span><svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" x=\"0px\" y=\"0px\" width=\"32px\" height=\"32px\" viewBox=\"0 0 32 32\" enable-background=\"new 0 0 32 32\" xml:space=\"preserve\">" + svgIcons.sms + "</svg></a>";
	        	}
	        }
        }else{

            var currentSVGIcon;

            if(currentButton === "facebook")
            {
                currentSVGIcon = svgIcons.facebook;
            }
            else if(currentButton === "twitter")
            {
                currentSVGIcon = svgIcons.twitter;
            }
            else if(currentButton === "googleplus")
            {
                currentSVGIcon = svgIcons.googleplus;
            }
            else if(currentButton === "linkedin")
            {
                currentSVGIcon = svgIcons.linkedin;
            }
            else if(currentButton === "pinterest")
            {
                currentSVGIcon = svgIcons.pinterest;
            }
            else if(currentButton === "sms")
            {
                currentSVGIcon = svgIcons.sms;
            }

            if(sharebar_parameters.og_locale === "ar_AR"){
        		sharebarHTML += "<a onmousedown=\"utag_link(utag_data.titre_page, 'Barre de partage', 'Partager', '"+ currentButton +"');\" href=\"javascript:void(0)\" onclick=\"setCookie('share_" + currentButton + "', '" + window.location.pathname + "', 7300);shareClick('" + currentButton + "');\" title=\"" + staticTextLocale.accessibility.shareon + " " + currentButton + "\" class=\"share_" + currentButton + "\" id=\"share_" + currentButton + "\"><span class=\"sr-only\">" + currentButton + " " + staticTextLocale.accessibility.shareon + "</span><svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" x=\"0px\" y=\"0px\" width=\"32px\" height=\"32px\" viewBox=\"0 0 32 32\" enable-background=\"new 0 0 32 32\" xml:space=\"preserve\">" + currentSVGIcon + "</svg></a>";
        	}else{
            	sharebarHTML += "<a onmousedown=\"utag_link(utag_data.titre_page, 'Barre de partage', 'Partager', '"+ currentButton +"');\" href=\"javascript:void(0)\" onclick=\"setCookie('share_" + currentButton + "', '" + window.location.pathname + "', 7300);shareClick('" + currentButton + "');\" title=\"" + staticTextLocale.accessibility.shareon + " " + currentButton + "\" class=\"share_" + currentButton + "\" id=\"share_" + currentButton + "\"><span class=\"sr-only\">" + staticTextLocale.accessibility.shareon + " " + currentButton + "</span><svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" x=\"0px\" y=\"0px\" width=\"32px\" height=\"32px\" viewBox=\"0 0 32 32\" enable-background=\"new 0 0 32 32\" xml:space=\"preserve\">" + currentSVGIcon + "</svg></a>";
        	}
        }
    }
    sharebarHTML += "</div>";
    document.getElementById('sharebar').innerHTML = sharebarHTML;
    if(sharebar_parameters.background_color != null && sharebar_parameters.layout != null){
        document.getElementById('sharebar').className = sharebar_parameters.background_color + ' ' + sharebar_parameters.layout;
    }
    setVisitedLinks();
};

var showFollowBar = function(){
    var followbarHTML = "<p id=\"follow\">" + staticTextLocale.follow + "</p>";
    followbarHTML += "<div class=\"content\">";
    for(var i=0, len=visible_followbar_buttons.length;i<len;i++){
        var currentButton = visible_followbar_buttons[i].button;

        var currentSVGIcon;

        if(currentButton === "facebook")
        {
            if(typeof followbar_parameters.page_facebook !== "undefined" && followbar_parameters.page_facebook != null && followbar_parameters.page_facebook != ""){
                currentSVGIcon = svgIcons.facebook;
                var currentLang = jQuery('html').attr('lang');
                if(currentLang != 'ru'){
                    currentFollowPage = followbar_parameters.page_facebook;
                }else{
                    currentFollowPage = followbar_parameters.page_facebook_ru;
                }
            }else{
                currentSVGIcon = "";
                currentFollowPage = "";
            }
        }
        else if(currentButton === "twitter")
        {

            if(typeof followbar_parameters.page_twitter !== "undefined" && followbar_parameters.page_twitter != null && followbar_parameters.page_twitter != ""){
                currentSVGIcon = svgIcons.twitter;
                currentFollowPage = followbar_parameters.page_twitter;
            }else{
                currentSVGIcon = "";
                currentFollowPage = "";
            }
        }
        else if(currentButton === "googleplus")
        {
            if(typeof followbar_parameters.page_googleplus !== "undefined" && followbar_parameters.page_googleplus != null && followbar_parameters.page_googleplus != ""){
                currentSVGIcon = svgIcons.googleplus;
                currentFollowPage = followbar_parameters.page_googleplus;
            }else{
                currentSVGIcon = "";
                currentFollowPage = "";
            }

        }else if(currentButton === "linkedin")
        {
            if(typeof followbar_parameters.page_linkedin !== "undefined" && followbar_parameters.page_linkedin != null && followbar_parameters.page_linkedin != ""){
                currentSVGIcon = svgIcons.linkedin;
                currentFollowPage = followbar_parameters.page_linkedin;
            }else{
                currentSVGIcon = "";
                currentFollowPage = "";
            }

        }
        else if(currentButton === "pinterest")
        {
            if(typeof followbar_parameters.page_pinterest !== "undefined" && followbar_parameters.page_pinterest != null && followbar_parameters.page_pinterest != ""){
                currentSVGIcon = svgIcons.pinterest;
                currentFollowPage = followbar_parameters.page_pinterest;
            }else{
                currentSVGIcon = "";
                currentFollowPage = "";
            }

        }
        else if(currentButton === "slideshare")
        {
            if(typeof followbar_parameters.page_pinterest !== "undefined" && followbar_parameters.page_pinterest != null && followbar_parameters.page_slideshare != ""){
                currentSVGIcon = svgIcons.slideshare;
                currentFollowPage = followbar_parameters.page_slideshare;
            }else{
                currentSVGIcon = "";
                currentFollowPage = "";
            }

        }
        else if(currentButton === "instagram")
        {
            if(typeof followbar_parameters.page_instagram !== "undefined" && followbar_parameters.page_instagram != null && followbar_parameters.page_instagram != ""){
                currentSVGIcon = svgIcons.instagram;
                currentFollowPage = followbar_parameters.page_instagram;
            }else{
                currentSVGIcon = "";
                currentFollowPage = "";
            }

        }
        else if(currentButton === "newsletter")
        {
            if(typeof followbar_parameters.page_newsletter !== "undefined" && followbar_parameters.page_newsletter != null && followbar_parameters.page_newsletter != ""){
                currentSVGIcon = svgIcons.newsletter;
                currentFollowPage = followbar_parameters.page_newsletter;
            }else{
                currentSVGIcon = "";
                currentFollowPage = "";
            }

        }
        else if(currentButton === "youtube")
        {
            if(typeof followbar_parameters.page_youtube !== "undefined" && followbar_parameters.page_youtube != null && followbar_parameters.page_youtube != ""){
                currentSVGIcon = svgIcons.youtube;
                currentFollowPage = followbar_parameters.page_youtube;
            }else{
                currentSVGIcon = "";
                currentFollowPage = "";
            }

        }
        else if(currentButton === "dailymotion")
        {
            if(typeof followbar_parameters.page_dailymotion !== "undefined" && followbar_parameters.page_dailymotion != null && followbar_parameters.page_dailymotion != ""){
                currentSVGIcon = svgIcons.dailymotion;
                currentFollowPage = followbar_parameters.page_dailymotion;
            }else{
                currentSVGIcon = "";
                currentFollowPage = "";
            }

        }

        if(currentSVGIcon != null && currentFollowPage != null && currentSVGIcon != "" && currentFollowPage != ""){
        	if(currentButton == "newsletter"){
				followbarHTML += "<a  onmousedown=\"utag_link(utag_data.titre_page, 'Barre de partage', 'Suivez nous', '"+ currentButton +"');\" href=\"" + currentFollowPage + "\" target=\"_blank\" class=\"follow_" + currentButton + "\" onclick=\"setCookie('follow_" + currentButton + "', '" + window.location.pathname + "', 7300);\" id=\"follow_" + currentButton + "\"><span class=\"sr-only\">" + staticTextLocale.accessibility.newsletter + "</span><svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" x=\"0px\" y=\"0px\" width=\"32px\" height=\"32px\" viewBox=\"0 0 32 32\" enable-background=\"new 0 0 32 32\" xml:space=\"preserve\">" + currentSVGIcon + "</svg></a>";
        	}else{
        		if(followbar_parameters.locale == "ar_AR"){
        			followbarHTML += "<a onmousedown=\"utag_link(utag_data.titre_page, 'Barre de partage', 'Suivez nous', '"+ currentButton +"');\" href=\"" + currentFollowPage + "\" target=\"_blank\" class=\"follow_" + currentButton + "\" onclick=\"setCookie('follow_" + currentButton + "', '" + window.location.pathname + "', 7300);\" id=\"follow_" + currentButton + "\"><span class=\"sr-only\">" + currentButton + " " + staticTextLocale.accessibility.follow + "</span><svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" x=\"0px\" y=\"0px\" width=\"32px\" height=\"32px\" viewBox=\"0 0 32 32\" enable-background=\"new 0 0 32 32\" xml:space=\"preserve\">" + currentSVGIcon + "</svg></a>";
        		}else{
        			followbarHTML += "<a onmousedown=\"utag_link(utag_data.titre_page, 'Barre de partage', 'Suivez nous', '"+ currentButton +"');\" href=\"" + currentFollowPage + "\" target=\"_blank\" class=\"follow_" + currentButton + "\" onclick=\"setCookie('follow_" + currentButton + "', '" + window.location.pathname + "', 7300);\" id=\"follow_" + currentButton + "\"><span class=\"sr-only\">" + staticTextLocale.accessibility.follow + " " + currentButton + "</span><svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" x=\"0px\" y=\"0px\" width=\"32px\" height=\"32px\" viewBox=\"0 0 32 32\" enable-background=\"new 0 0 32 32\" xml:space=\"preserve\">" + currentSVGIcon + "</svg></a>";
        		}
        	}
        }
    }
    followbarHTML += "</div>";
    // document.getElementById('followbar').innerHTML = followbarHTML;
    // if(followbar_parameters.background_color != null && followbar_parameters.layout != null){
    //     document.getElementById('followbar').className = followbar_parameters.background_color + ' ' + followbar_parameters.layout;
    // }
    var followBars = document.getElementsByClassName('followbar');
    for(var i=0;i<followBars.length;i++) {
        followBars[i].innerHTML = followbarHTML;
        if(followbar_parameters.background_color != null && followbar_parameters.layout != null){
            followBars[i].className += ' ' + followbar_parameters.background_color + ' ' + followbar_parameters.layout;
        }
    }
    setVisitedLinks();
};


function setCookie(name, value, daysUntilExpires) {
    var d = new Date();
    var cookie;
    d.setTime(d.getTime() + (daysUntilExpires*24*60*60*1000));
    var expires = "expires="+d.toUTCString();
    var splitedPath = window.location.pathname.split("/");
    if(splitedPath[splitedPath.length-1].indexOf(".") > -1) {

        var path = "";
        for(var i=0;i<splitedPath.length-1;i++) {
            path += splitedPath[i] + "/";
        }
        cookie = name + "|" + splitedPath[splitedPath.length-1] + "=" + value + "; " + expires + "; path=" + path;
        document.cookie = cookie;

    } else {
        cookie = name + "=" + value + "; " + expires + "; path=" + window.location.pathname;
        document.cookie = cookie;
    }
    setVisitedLinks();
}

function checkCookie(cname) {
    var splitedPath = window.location.pathname.split("/");
    var name = "";
    if(splitedPath[splitedPath.length-1].indexOf(".") > -1) {
        name += cname + "|" + splitedPath[splitedPath.length-1] + "=";
    } else {
        name += cname + "=";
    }
    var cookies = document.cookie.split(';');
    for(var i=0; i<cookies.length; i++) {
        var cookie = cookies[i];
        while (cookie.charAt(0) === ' ')
        {
            cookie = cookie.substring(1);
        }
        if (cookie.indexOf(name) === 0){
            if(document.getElementById(cname)){
                var url = cookie.split('=');
                if(url[1] == window.location.pathname){
                    document.getElementById(cname).className=cname + " visited";
                }
            }
            return true;
        }
    }
    return false;
}

function checkFollowCookie(cname) {
    var splitedPath = window.location.pathname.split("/");
    var name = "";
    if(splitedPath[splitedPath.length-1].indexOf(".") > -1) {
        name += cname + "|" + splitedPath[splitedPath.length-1] + "=";
    } else {
        name += cname + "=";
    }
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0) === ' ')
        {
            c = c.substring(1);
        }
        if (c.indexOf(name) === 0){
            if(document.getElementsByClassName(cname)){
                for(var j=0;j<document.getElementsByClassName(cname).length;j++) {
                    document.getElementsByClassName(cname)[j].className=cname + " visited";
                }
            }
        }

    }
    return "";
}

var setVisitedLinks = function(){
    if(typeof visible_sharebar_buttons !== "undefined"){
        for(var i=0, len=visible_sharebar_buttons.length;i<len;i++){
            checkCookie('share_' + visible_sharebar_buttons[i].button);
        }
    }
    if(typeof visible_followbar_buttons !== "undefined"){
        for(var i=0, len=visible_followbar_buttons.length;i<len;i++){
            checkFollowCookie('follow_' + visible_followbar_buttons[i].button);
        }
    }
};

var goToGmail = function(){
    var to = document.getElementById("to").value;
    var subject = document.getElementById("subject").value;
    var message = document.getElementById("message").value;
    window.open("https://mail.google.com/mail/?view=cm&fs=1&to=" + to + "&su=" + subject + "&body=" + message + "&ui=2&tf=1");
    closeMail();
};

var goToYahoo = function(){
    var to = document.getElementById("to").value;
    var subject = document.getElementById("subject").value;
    var message = document.getElementById("message").value;
    window.open("http://us-mg.mail.yahoo.com/neo/launch?action=compose&To=" + to + "&Subj=" + subject + "&Body=" + message + "#mail");
    closeMail();
};

var openMail = function(){
    document.getElementById('contentmail').innerHTML = "<div id=\"email\"><div id=\"toplabel\"><span class=\"bold\">" + sharebar_parameters.email_popin_title + "</span><svg id=\"close\" onClick=\"closeMail()\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" version=\"1.1\" id=\"Layer_1\" x=\"0px\" y=\"0px\" width=\"16px\" height=\"16px\" viewBox=\"0 0 512 512\" style=\"enable-background:new 0 0 512 512;\" xml:space=\"preserve\"><path d=\"M437.5,386.6L306.9,256l130.6-130.6c14.1-14.1,14.1-36.8,0-50.9c-14.1-14.1-36.8-14.1-50.9,0L256,205.1L125.4,74.5  c-14.1-14.1-36.8-14.1-50.9,0c-14.1,14.1-14.1,36.8,0,50.9L205.1,256L74.5,386.6c-14.1,14.1-14.1,36.8,0,50.9  c14.1,14.1,36.8,14.1,50.9,0L256,306.9l130.6,130.6c14.1,14.1,36.8,14.1,50.9,0C451.5,423.4,451.5,400.6,437.5,386.6z\" fill=\"#FFFFFF\"/></svg></div><form action=\"scripts/sendmail.php\" method=\"post\" id=\"sendmail\"><label for=\"to\"><span class=\"bold\">" + staticTextLocale.to + ":</span> (" + staticTextLocale.email + ")</label><textarea autofocus name=\"to\" id=\"to\"></textarea><label for=\"from\"><span class=\"bold\">" + staticTextLocale.from + ":</span> (" + staticTextLocale.email + ")</label><input type=\"text\" value=\"\" name=\"from\" id=\"from\" /><label for=\"subject\"><span class=\"bold\">" + staticTextLocale.subject + ":</span></label><input type=\"text\" value=\"" + sharebar_parameters.email_subject + "\" name=\"subject\" id=\"subject\" /><label for=\"message\"><span class=\"bold\">" + staticTextLocale.message + ":</span> (" + staticTextLocale.optional + ")</label><textarea name=\"message\" id=\"message\">" + sharebar_parameters.email_message + "</textarea><div class=\"buttons\"><input type=\"button\" value=\"" + staticTextLocale.cancel + "\" onClick=\"closeMail()\" /><input type=\"submit\" value=\"" + staticTextLocale.send + "\" /></div><p id=\"more\">" + staticTextLocale.more + " : <img src=\"img/gmail.png\" alt=\"open gmail\" onClick=\"goToGmail()\" /> <img src=\"img/yahoo.png\" alt=\"open yahoo\" onClick=\"goToYahoo()\" /></p></form></div>";
};

var closeMail = function(){
    document.getElementById('contentmail').innerHTML = "";
};

var getDeviceAndVersion = function(){
        var nAgt = navigator.userAgent;
        var nVer = navigator.appVersion;
        var os = 'unknown';
        var clientStrings = [
            {s:'Windows 3.11', r:/Win16/},
            {s:'Windows 95', r:/(Windows 95|Win95|Windows_95)/},
            {s:'Windows ME', r:/(Win 9x 4.90|Windows ME)/},
            {s:'Windows 98', r:/(Windows 98|Win98)/},
            {s:'Windows CE', r:/Windows CE/},
            {s:'Windows 2000', r:/(Windows NT 5.0|Windows 2000)/},
            {s:'Windows XP', r:/(Windows NT 5.1|Windows XP)/},
            {s:'Windows Server 2003', r:/Windows NT 5.2/},
            {s:'Windows Vista', r:/Windows NT 6.0/},
            {s:'Windows 7', r:/(Windows 7|Windows NT 6.1)/},
            {s:'Windows 8.1', r:/(Windows 8.1|Windows NT 6.3)/},
            {s:'Windows 8', r:/(Windows 8|Windows NT 6.2)/},
            {s:'Windows NT 4.0', r:/(Windows NT 4.0|WinNT4.0|WinNT|Windows NT)/},
            {s:'Windows ME', r:/Windows ME/},
            {s:'Android', r:/Android/},
            {s:'Open BSD', r:/OpenBSD/},
            {s:'Sun OS', r:/SunOS/},
            {s:'Linux', r:/(Linux|X11)/},
            {s:'iOS', r:/(iPhone|iPad|iPod)/},
            {s:'Mac OS X', r:/Mac OS X/},
            {s:'Mac OS', r:/(MacPPC|MacIntel|Mac_PowerPC|Macintosh)/},
            {s:'QNX', r:/QNX/},
            {s:'UNIX', r:/UNIX/},
            {s:'BeOS', r:/BeOS/},
            {s:'OS/2', r:/OS\/2/},
            {s:'Search Bot', r:/(nuhk|Googlebot|Yammybot|Openbot|Slurp|MSNBot|Ask Jeeves\/Teoma|ia_archiver)/}
        ];
        for (var id in clientStrings) {
            var cs = clientStrings[id];
            if (cs.r.test(nAgt)) {
                os = cs.s;
                break;
            }
        }
        var osVersion = 'unknown';
        if (/Windows/.test(os)) {
            osVersion = /Windows (.*)/.exec(os)[1];
            os = 'Windows';
        }
        switch (os) {
            case 'Mac OS X':
                osVersion = /Mac OS X (10[\.\_\d]+)/.exec(nAgt)[1];
                break;

            case 'Android':
                osVersion = /Android ([\.\_\d]+)/.exec(nAgt)[1];
                break;

            case 'iOS':
                osVersion = /OS (\d+)_(\d+)_?(\d+)?/.exec(nVer);
                osVersion = osVersion[1] + '.' + osVersion[2] + '.' + (osVersion[3] | 0);
                break;
        }
        window.jscd = {
            os: os,
            osVersion: osVersion
        };
        return {
            os: jscd.os,
            version: jscd.osVersion.substring(0,1)
        };
    };

    var openSMS = function(message){
        var url;
        // alert('OS : ' + getDeviceAndVersion().os);
        // alert('Version : ' + getDeviceAndVersion().version);
        if(getDeviceAndVersion().os === "iOS"){
            if(getDeviceAndVersion().version === "8"){
                url = "sms:&body=" + encodeURIComponent(message);
            }else if(getDeviceAndVersion().version === "7"){
                url = "sms:;body=" + encodeURIComponent(message);//show message only if there is already a conversation
            }else{
                url = "sms:;body=" + encodeURIComponent(message);
            }
        }else if(getDeviceAndVersion().os === "Android"){
            url = "sms:?body=" + encodeURIComponent(message);
        }else{
            url = "sms:";
        }
        location.href = url;
    };

var getShares = function(){
    getFacebookShare();
    //getTwitterShare();
    getPinterestShare();
    getLinkedinShare();
    if(typeof googleshares !== "undefined"){
        if(googleshares <= 0){
            shares.google = googleshares;
        }
    }
};



//show social bars on window load if autoLoad parameter is set to true
window.onload = function(){
	if(typeof sharebar_parameters !== "undefined"){
		if(typeof sharebar_parameters.auto_load !== "undefined" && sharebar_parameters.auto_load !== null){
			if(document.getElementById('sharebar')){
				if(sharebar_parameters.auto_load === true){
					showShareBar();
				}
				//getShares();

				/*if(typeof sharebar_parameters.counter_reload_time !== "undefined"){
					if(sharebar_parameters.counter_reload_time > 0){
						var time = sharebar_parameters.counter_reload_time * 1000;
						window.setInterval(function(){ getShares(); }, time);
					}
				}*/
			}
		}
	}
	if(typeof followbar_parameters !== "undefined"){
		if(typeof followbar_parameters.auto_load !== "undefined" && followbar_parameters.auto_load !== null){
			if(document.getElementsByClassName('followbar')){
				if(followbar_parameters.auto_load === true){
					showFollowBar();
				}
			}
		}
	}


	var t = window.setInterval(function(){
		var total = shares.facebook + shares.twitter + shares.pinterest + shares.linkedin + shares.google + shares.user;
		if(typeof sharebar_parameters !== "undefined"){
			if(document.getElementById('sharebar') && typeof sharebar_parameters.show_counter !== "undefined" && sharebar_parameters.show_counter){
				if(total <= 0){
			        document.getElementById('countertext').innerHTML = staticTextLocale.toshare;
			        document.getElementById('counterlabel').className = "nocounter";
			    }else if(total == 1){
			        document.getElementById('countertext').innerHTML = staticTextLocale.share;
			        document.getElementById('counterlabel').className = "";
			    }else{
			        document.getElementById('countertext').innerHTML = staticTextLocale.shares;
			        document.getElementById('counterlabel').className = "";
			    }
			}
		}
	}, 500);
	window.setTimeout(function(){clearInterval(t);}, 8000);
	checkIfRightToLeft();




	if($('#sharebar.horizontal').length){
		$("#sharebar.horizontal #counterlabel")[0].style.maxWidth = Math.round($("#sharebar.horizontal #counterlabel")[0].offsetWidth) + "px";
	}
		if($('.followbar.horizontal').length){
            for(var i=0;i<$('.followbar.horizontal').length;i++) {
		  $(".followbar.horizontal #follow")[i].style.minWidth = Math.round($(".followbar.horizontal #follow")[i].offsetWidth) + "px";
        }
	}
	if($(document).width() < 480){
		if($('#sharebar.horizontal').length){
	  		$("#sharebar.horizontal .content")[0].style.maxWidth = "calc(100% - " + ($('#sharebar.horizontal #counterlabel')[0].offsetWidth + 12) + "px)";
	  	}
	  	if($('.followbar.horizontal').length){
            for(var i=0;i<$('.followbar.horizontal').length;i++) {
		  	   $(".followbar.horizontal .content")[i].style.maxWidth = "calc(100% - " + ($('.followbar.horizontal #follow')[i].offsetWidth + 12) + "px)";
            }
	  	}
	}else if($(document).width() < 768){
		if($('#sharebar.horizontal').length){
	  		$("#sharebar.horizontal .content")[0].style.maxWidth = "calc(100% - " + ($('#sharebar.horizontal #counterlabel')[0].offsetWidth + 0.0256*$(document).width() + 1) + "px)";
	  	}
	  	if($('.followbar.horizontal').length){
            for(var i=0;i<$('.followbar.horizontal').length;i++) {
		  	   $(".followbar.horizontal .content")[i].style.maxWidth = "calc(100% - " + ($('.followbar.horizontal #follow')[i].offsetWidth + 0.0256*$(document).width() + 1) + "px)";
            }
	  	}
	}else if($(document).width() < 960){
		if($('#sharebar.horizontal').length){
	  		$("#sharebar.horizontal .content")[0].style.maxWidth = "calc(100% - " + ($('#sharebar.horizontal #counterlabel')[0].offsetWidth + 0.0327*$(document).width() + 1) + "px)";
	  	}
	  	if($('.followbar.horizontal').length){
            for(var i=0;i<$('.followbar.horizontal').length;i++) {
		  	   $(".followbar.horizontal .content")[i].style.maxWidth = "calc(100% - " + ($('.followbar.horizontal #follow')[i].offsetWidth + 0.0327*$(document).width() + 1) + "px)";
            }
	  	}
	}else{
		if($('#sharebar.horizontal').length){
	  		$("#sharebar.horizontal .content")[0].style.maxWidth = "calc(100% - " + ($('#sharebar.horizontal #counterlabel')[0].offsetWidth + 25) + "px)";
	  	}
	  	if($('.followbar.horizontal').length){
            for(var i=0;i<$('.followbar.horizontal').length;i++) {
		  	   $(".followbar.horizontal .content")[i].style.maxWidth = "calc(100% - " + ($('.followbar.horizontal #follow')[i].offsetWidth + 20) + "px)";
            }
	  	}
	}


};
//used when window is resized
	window.onresize = function(){
		if($('#sharebar.horizontal').length){
			$("#sharebar.horizontal #counterlabel")[0].style.maxWidth = Math.round($("#sharebar.horizontal #counterlabel")[0].offsetWidth) + "px";
		}
			if($('.followbar.horizontal').length){
            for(var i=0;i<$('.followbar.horizontal').length;i++) {
			 $(".followbar.horizontal #follow")[i].style.minWidth = Math.round($(".followbar.horizontal #follow")[i].offsetWidth) + "px";
            }
		}
		if($(document).width() < 480){
			if($('#sharebar.horizontal').length){
		  		$("#sharebar.horizontal .content")[0].style.maxWidth = "calc(100% - " + ($('#sharebar.horizontal #counterlabel')[0].offsetWidth + 12) + "px)";
		  	}
		  	if($('.followbar.horizontal').length){
            for(var i=0;i<$('.followbar.horizontal').length;i++) {
			  	  $(".followbar.horizontal .content")[i].style.maxWidth = "calc(100% - " + ($('.followbar.horizontal #follow')[i].offsetWidth + 12) + "px)";
                }
		  	}
		}else if($(document).width() < 768){
			if($('#sharebar.horizontal').length){
		  		$("#sharebar.horizontal .content")[0].style.maxWidth = "calc(100% - " + ($('#sharebar.horizontal #counterlabel')[0].offsetWidth + 0.0256*$(document).width() + 1) + "px)";
		  	}
		  	if($('.followbar.horizontal').length){
            for(var i=0;i<$('.followbar.horizontal').length;i++) {
			  	  $(".followbar.horizontal .content")[i].style.maxWidth = "calc(100% - " + ($('.followbar.horizontal #follow')[i].offsetWidth + 0.0256*$(document).width() + 1) + "px)";
                }
		  	}
		}else if($(document).width() < 960){
			if($('#sharebar.horizontal').length){
		  		$("#sharebar.horizontal .content")[0].style.maxWidth = "calc(100% - " + ($('#sharebar.horizontal #counterlabel')[0].offsetWidth + 0.0327*$(document).width() + 1) + "px)";
		  	}
		  	if($('.followbar.horizontal').length){
            for(var i=0;i<$('.followbar.horizontal').length;i++) {
			  	  $(".followbar.horizontal .content")[i].style.maxWidth = "calc(100% - " + ($('.followbar.horizontal #follow')[i].offsetWidth + 0.0327*$(document).width() + 1) + "px)";
                }
		  	}
		}else{
			if($('#sharebar.horizontal').length){
		  		$("#sharebar.horizontal .content")[0].style.maxWidth = "calc(100% - " + ($('#sharebar.horizontal #counterlabel')[0].offsetWidth + 25) + "px)";
		  	}
		  	if($('.followbar.horizontal').length){
            for(var i=0;i<$('.followbar.horizontal').length;i++) {
			  	  $(".followbar.horizontal .content")[i].style.maxWidth = "calc(100% - " + ($('.followbar.horizontal #follow')[i].offsetWidth + 20) + "px)";
                }
		  	}
		}
	};
	window.onclick = function(){
	    $ = jQuery;
		if($('#sharebar.horizontal').length){
			$("#sharebar.horizontal #counterlabel")[0].style.maxWidth = Math.round($("#sharebar.horizontal #counterlabel")[0].offsetWidth) + "px";
		}
			if($('.followbar.horizontal').length){
            for(var i=0;i<$('.followbar.horizontal').length;i++) {
			 $(".followbar.horizontal #follow")[i].style.minWidth = Math.round($(".followbar.horizontal #follow")[i].offsetWidth) + "px";
            }
		}
		if($(document).width() < 480){
			if($('#sharebar.horizontal').length){
		  		$("#sharebar.horizontal .content")[0].style.maxWidth = "calc(100% - " + ($('#sharebar.horizontal #counterlabel')[0].offsetWidth + 12) + "px)";
		  	}
		  	if($('.followbar.horizontal').length){
            for(var i=0;i<$('.followbar.horizontal').length;i++) {
			  	  $(".followbar.horizontal .content")[i].style.maxWidth = "calc(100% - " + ($('.followbar.horizontal #follow')[i].offsetWidth + 12) + "px)";
                }
		  	}
		}else if($(document).width() < 768){
			if($('#sharebar.horizontal').length){
		  		$("#sharebar.horizontal .content")[0].style.maxWidth = "calc(100% - " + ($('#sharebar.horizontal #counterlabel')[0].offsetWidth + 0.0256*$(document).width() + 1) + "px)";
		  	}
		  	if($('.followbar.horizontal').length){
            for(var i=0;i<$('.followbar.horizontal').length;i++) {
			  	  $(".followbar.horizontal .content")[i].style.maxWidth = "calc(100% - " + ($('.followbar.horizontal #follow')[i].offsetWidth + 0.0256*$(document).width() + 1) + "px)";
                }
		  	}
		}else if($(document).width() < 960){
			if($('#sharebar.horizontal').length){
		  		$("#sharebar.horizontal .content")[0].style.maxWidth = "calc(100% - " + ($('#sharebar.horizontal #counterlabel')[0].offsetWidth + 0.0327*$(document).width() + 1) + "px)";
		  	}
		  	if($('.followbar.horizontal').length){
            for(var i=0;i<$('.followbar.horizontal').length;i++) {
			  	  $(".followbar.horizontal .content")[i].style.maxWidth = "calc(100% - " + ($('.followbar.horizontal #follow')[i].offsetWidth + 0.0327*$(document).width() + 1) + "px)";
                }
		  	}
		}else{
			if($('#sharebar.horizontal').length){
		  		$("#sharebar.horizontal .content")[0].style.maxWidth = "calc(100% - " + ($('#sharebar.horizontal #counterlabel')[0].offsetWidth + 25) + "px)";
		  	}
		  	if($('.followbar.horizontal').length){
            for(var i=0;i<$('.followbar.horizontal').length;i++) {
			  	  $(".followbar.horizontal .content")[i].style.maxWidth = "calc(100% - " + ($('.followbar.horizontal #follow')[i].offsetWidth + 20) + "px)";
                }
		  	}
		}
	};
