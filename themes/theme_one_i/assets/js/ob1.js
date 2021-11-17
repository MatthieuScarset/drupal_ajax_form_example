/*!
  * OB1 (https://gitlab.forge.orange-labs.fr/boosted/ob1/)
  * Copyright 2018-2021 The OB1 Authors
  * Copyright 2018-2021 Orange
  * Based on fork of Bootstrap: Boosted
  * Boosted
  * Copyright 2014-2021 The Boosted Authors
  * Licensed under MIT (https://github.com/Orange-OpenSource/Orange-Boosted-Bootstrap/blob/master/LICENSE)
  */
(function (global, factory) {
  typeof exports === 'object' && typeof module !== 'undefined' ? factory(exports, require('jquery'), require('popper.js')) :
  typeof define === 'function' && define.amd ? define(['exports', 'jquery', 'popper.js'], factory) :
  (global = global || self, factory(global.ob1 = {}, global.jQuery, global.Popper));
}(this, (function (exports, jquery, popper) { 'use strict';

  jquery = jquery && Object.prototype.hasOwnProperty.call(jquery, 'default') ? jquery['default'] : jquery;
  popper = popper && Object.prototype.hasOwnProperty.call(popper, 'default') ? popper['default'] : popper;

  var Accordion = /*#__PURE__*/function () {
    var _proto = Accordion.prototype;

    _proto.toogleBodyDisplay = function toogleBodyDisplay(elementIndex) {
      var element = this.accordionsCardsLinks[elementIndex];
      var isExpanded = element.getAttribute("aria-expanded");
      var dataTargetAttr = element.getAttribute("data-target");

      if (isExpanded === "true") {
        element.setAttribute("aria-expanded", "false");

        if (!this.findHashTag(dataTargetAttr)) {
          document.getElementById(dataTargetAttr).classList.remove("show");
        }
        element.classList.remove("show");
      } else {
        // si l'accordéon n'est pas en mode multi, fermer toutes les lignes
        if (!element.parentElement.parentElement.classList.contains("multi")) {
          for (var i = 0; i < this.accordionsCardsLinks.length; i++) {
            var elt = this.accordionsCardsLinks[i];
            elt.classList.remove("show");
          }
        } // ouvrir la ligne sélectionnée


        element.setAttribute("aria-expanded", "true");

        if (!this.findHashTag(dataTargetAttr)) {
          document.getElementById(element.getAttribute("data-target")).classList.add("show");
        }
        element.classList.add("show");
      }
    } // Verifier si un string a un hashtag préfixé au debut
    ;

    _proto.findHashTag = function findHashTag(str) {
      return typeof str === "string" && str.indexOf("#") === 0;
    };

    _proto.init = function init(container) {
      var _this = this;

      this.container = container;
      this.accordionsCardsLinks = container.querySelectorAll(".card-header a");

      this._onClick = function (index) {
        _this.toogleBodyDisplay(index);
      };

      this._onClicks = [];

      for (var i = 0; i < this.accordionsCardsLinks.length; i++) {
        var linkToSet = this.accordionsCardsLinks[i]; // On met un listener pour pouvoir ouvrir ou fermer un bloc de l'accordéon

        this._onClicks[i] = this._onClick.bind(this, i);
        linkToSet.addEventListener("click", this._onClicks[i]);
      }
    };

    function Accordion(container) {
      if (container) {
        if (typeof container.dataset.ref === "undefined") {
          this.ref = Math.random();
          Accordion.refs[this.ref] = this;
          container.dataset.ref = this.ref;
          this.init(container);
        } else {
          // If this element has already been instantiated, use the existing reference.
          return Accordion.refs[container.dataset.ref];
        }
      }
    }
    /**
     * Décharge le composant
     */


    _proto.dispose = function dispose() {
      // suppression de tous les event listeners qui ont été créés
      this.accordionsCardsLinks = container.querySelectorAll(".card-header a");

      for (var i = 0; i < this.accordionsCardsLinks.length; i++) {
        var linkToSet = this.accordionsCardsLinks[i];
        linkToSet.removeEventListener("click", this._onClicks[i]);
      }
    };

    return Accordion;
  }();

  Accordion.refs = {};
  document.addEventListener("DOMContentLoaded", function () {
    var accordions = document.querySelectorAll(".accordion");
    [].forEach.call(accordions, function (accordion) {
      new Accordion(accordion);
    });
  }); // rattachement au contexte window pour pouvoir l'utiliser en dehors du JS

  window.Accordion = Accordion;

  var commonjsGlobal = typeof globalThis !== 'undefined' ? globalThis : typeof window !== 'undefined' ? window : typeof global !== 'undefined' ? global : typeof self !== 'undefined' ? self : {};

  function createCommonjsModule(fn, module) {
  	return module = { exports: {} }, fn(module, module.exports), module.exports;
  }

  var util = createCommonjsModule(function (module, exports) {
  /*!
    * Boosted v4.3.1 (https://boosted.orange.com)
    * Copyright 2014-2019 The Boosted Authors
    * Copyright 2014-2019 Orange
    * Licensed under MIT (https://github.com/orange-opensource/orange-boosted-bootstrap/blob/master/LICENSE)
    * This a fork of Bootstrap : Initial license below
    * Bootstrap util.js v4.3.1 (https://boosted.orange.com)
    * Copyright 2011-2019 The Boosted Authors (https://github.com/Orange-OpenSource/Orange-Boosted-Bootstrap/graphs/contributors)
    * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
    */
  (function (global, factory) {
     module.exports = factory(jquery) ;
  }(commonjsGlobal, function ($) {
    $ = $ && $.hasOwnProperty('default') ? $['default'] : $;

    /**
     * --------------------------------------------------------------------------
     * Bootstrap (v4.3.1): util.js
     * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
     * --------------------------------------------------------------------------
     */
    /**
     * ------------------------------------------------------------------------
     * Private TransitionEnd Helpers
     * ------------------------------------------------------------------------
     */

    var TRANSITION_END = 'transitionend';
    var MAX_UID = 1000000;
    var MILLISECONDS_MULTIPLIER = 1000; // Shoutout AngusCroll (https://goo.gl/pxwQGp)

    function toType(obj) {
      return {}.toString.call(obj).match(/\s([a-z]+)/i)[1].toLowerCase();
    }

    function getSpecialTransitionEndEvent() {
      return {
        bindType: TRANSITION_END,
        delegateType: TRANSITION_END,
        handle: function handle(event) {
          if ($(event.target).is(this)) {
            return event.handleObj.handler.apply(this, arguments); // eslint-disable-line prefer-rest-params
          }

          return undefined; // eslint-disable-line no-undefined
        }
      };
    }

    function transitionEndEmulator(duration) {
      var _this = this;

      var called = false;
      $(this).one(Util.TRANSITION_END, function () {
        called = true;
      });
      setTimeout(function () {
        if (!called) {
          Util.triggerTransitionEnd(_this);
        }
      }, duration);
      return this;
    }

    function setTransitionEndSupport() {
      $.fn.emulateTransitionEnd = transitionEndEmulator;
      $.event.special[Util.TRANSITION_END] = getSpecialTransitionEndEvent();
    }
    /**
     * --------------------------------------------------------------------------
     * Public Util Api
     * --------------------------------------------------------------------------
     */


    var Util = {
      TRANSITION_END: 'bsTransitionEnd',
      getUID: function getUID(prefix) {
        do {
          // eslint-disable-next-line no-bitwise
          prefix += ~~(Math.random() * MAX_UID); // "~~" acts like a faster Math.floor() here
        } while (document.getElementById(prefix));

        return prefix;
      },
      getSelectorFromElement: function getSelectorFromElement(element) {
        var selector = element.getAttribute('data-target');

        if (!selector || selector === '#') {
          var hrefAttr = element.getAttribute('href');
          selector = hrefAttr && hrefAttr !== '#' ? hrefAttr.trim() : '';
        }

        try {
          return document.querySelector(selector) ? selector : null;
        } catch (err) {
          return null;
        }
      },
      getTransitionDurationFromElement: function getTransitionDurationFromElement(element) {
        if (!element) {
          return 0;
        } // Get transition-duration of the element


        var transitionDuration = $(element).css('transition-duration');
        var transitionDelay = $(element).css('transition-delay');
        var floatTransitionDuration = parseFloat(transitionDuration);
        var floatTransitionDelay = parseFloat(transitionDelay); // Return 0 if element or transition duration is not found

        if (!floatTransitionDuration && !floatTransitionDelay) {
          return 0;
        } // If multiple durations are defined, take the first


        transitionDuration = transitionDuration.split(',')[0];
        transitionDelay = transitionDelay.split(',')[0];
        return (parseFloat(transitionDuration) + parseFloat(transitionDelay)) * MILLISECONDS_MULTIPLIER;
      },
      reflow: function reflow(element) {
        return element.offsetHeight;
      },
      triggerTransitionEnd: function triggerTransitionEnd(element) {
        $(element).trigger(TRANSITION_END);
      },
      // TODO: Remove in v5
      supportsTransitionEnd: function supportsTransitionEnd() {
        return Boolean(TRANSITION_END);
      },
      isElement: function isElement(obj) {
        return (obj[0] || obj).nodeType;
      },
      typeCheckConfig: function typeCheckConfig(componentName, config, configTypes) {
        for (var property in configTypes) {
          if (Object.prototype.hasOwnProperty.call(configTypes, property)) {
            var expectedTypes = configTypes[property];
            var value = config[property];
            var valueType = value && Util.isElement(value) ? 'element' : toType(value);

            if (!new RegExp(expectedTypes).test(valueType)) {
              throw new Error(componentName.toUpperCase() + ": " + ("Option \"" + property + "\" provided type \"" + valueType + "\" ") + ("but expected type \"" + expectedTypes + "\"."));
            }
          }
        }
      },
      findShadowRoot: function findShadowRoot(element) {
        if (!document.documentElement.attachShadow) {
          return null;
        } // Can find the shadow root otherwise it'll return the document


        if (typeof element.getRootNode === 'function') {
          var root = element.getRootNode();
          return root instanceof ShadowRoot ? root : null;
        }

        if (element instanceof ShadowRoot) {
          return element;
        } // when we don't find a shadow root


        if (!element.parentNode) {
          return null;
        }

        return Util.findShadowRoot(element.parentNode);
      }
    };
    setTransitionEndSupport();

    return Util;

  }));

  });

  var alert = createCommonjsModule(function (module, exports) {
  /*!
    * Boosted v4.3.1 (https://boosted.orange.com)
    * Copyright 2014-2019 The Boosted Authors
    * Copyright 2014-2019 Orange
    * Licensed under MIT (https://github.com/orange-opensource/orange-boosted-bootstrap/blob/master/LICENSE)
    * This a fork of Bootstrap : Initial license below
    * Bootstrap alert.js v4.3.1 (https://boosted.orange.com)
    * Copyright 2011-2019 The Boosted Authors (https://github.com/Orange-OpenSource/Orange-Boosted-Bootstrap/graphs/contributors)
    * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
    */
  (function (global, factory) {
     module.exports = factory(jquery, util) ;
  }(commonjsGlobal, function ($, Util) {
    $ = $ && $.hasOwnProperty('default') ? $['default'] : $;
    Util = Util && Util.hasOwnProperty('default') ? Util['default'] : Util;

    function _defineProperties(target, props) {
      for (var i = 0; i < props.length; i++) {
        var descriptor = props[i];
        descriptor.enumerable = descriptor.enumerable || false;
        descriptor.configurable = true;
        if ("value" in descriptor) descriptor.writable = true;
        Object.defineProperty(target, descriptor.key, descriptor);
      }
    }

    function _createClass(Constructor, protoProps, staticProps) {
      if (protoProps) _defineProperties(Constructor.prototype, protoProps);
      if (staticProps) _defineProperties(Constructor, staticProps);
      return Constructor;
    }

    /**
     * ------------------------------------------------------------------------
     * Constants
     * ------------------------------------------------------------------------
     */

    var NAME = 'alert';
    var VERSION = '4.3.1';
    var DATA_KEY = 'bs.alert';
    var EVENT_KEY = "." + DATA_KEY;
    var DATA_API_KEY = '.data-api';
    var JQUERY_NO_CONFLICT = $.fn[NAME];
    var Selector = {
      DISMISS: '[data-dismiss="alert"]'
    };
    var Event = {
      CLOSE: "close" + EVENT_KEY,
      CLOSED: "closed" + EVENT_KEY,
      CLICK_DATA_API: "click" + EVENT_KEY + DATA_API_KEY
    };
    var ClassName = {
      ALERT: 'alert',
      FADE: 'fade',
      SHOW: 'show'
      /**
       * ------------------------------------------------------------------------
       * Class Definition
       * ------------------------------------------------------------------------
       */

    };

    var Alert =
    /*#__PURE__*/
    function () {
      function Alert(element) {
        this._element = element;
      } // Getters


      var _proto = Alert.prototype;

      // Public
      _proto.close = function close(element) {
        var rootElement = this._element;

        if (element) {
          rootElement = this._getRootElement(element);
        }

        var customEvent = this._triggerCloseEvent(rootElement);

        if (customEvent.isDefaultPrevented()) {
          return;
        }

        this._removeElement(rootElement);
      };

      _proto.dispose = function dispose() {
        $.removeData(this._element, DATA_KEY);
        this._element = null;
      } // Private
      ;

      _proto._getRootElement = function _getRootElement(element) {
        var selector = Util.getSelectorFromElement(element);
        var parent = false;

        if (selector) {
          parent = document.querySelector(selector);
        }

        if (!parent) {
          parent = $(element).closest("." + ClassName.ALERT)[0];
        }

        return parent;
      };

      _proto._triggerCloseEvent = function _triggerCloseEvent(element) {
        var closeEvent = $.Event(Event.CLOSE);
        $(element).trigger(closeEvent);
        return closeEvent;
      };

      _proto._removeElement = function _removeElement(element) {
        var _this = this;

        $(element).removeClass(ClassName.SHOW);

        if (!$(element).hasClass(ClassName.FADE)) {
          this._destroyElement(element);

          return;
        }

        var transitionDuration = Util.getTransitionDurationFromElement(element);
        $(element).one(Util.TRANSITION_END, function (event) {
          return _this._destroyElement(element, event);
        }).emulateTransitionEnd(transitionDuration);
      };

      _proto._destroyElement = function _destroyElement(element) {
        $(element).detach().trigger(Event.CLOSED).remove();
      } // Static
      ;

      Alert._jQueryInterface = function _jQueryInterface(config) {
        return this.each(function () {
          var $element = $(this);
          var data = $element.data(DATA_KEY);

          if (!data) {
            data = new Alert(this);
            $element.data(DATA_KEY, data);
          }

          if (config === 'close') {
            data[config](this);
          }
        });
      };

      Alert._handleDismiss = function _handleDismiss(alertInstance) {
        return function (event) {
          if (event) {
            event.preventDefault();
          }

          alertInstance.close(this);
        };
      };

      _createClass(Alert, null, [{
        key: "VERSION",
        get: function get() {
          return VERSION;
        }
      }]);

      return Alert;
    }();
    /**
     * ------------------------------------------------------------------------
     * Data Api implementation
     * ------------------------------------------------------------------------
     */


    $(document).on(Event.CLICK_DATA_API, Selector.DISMISS, Alert._handleDismiss(new Alert()));
    /**
     * ------------------------------------------------------------------------
     * jQuery
     * ------------------------------------------------------------------------
     */

    $.fn[NAME] = Alert._jQueryInterface;
    $.fn[NAME].Constructor = Alert;

    $.fn[NAME].noConflict = function () {
      $.fn[NAME] = JQUERY_NO_CONFLICT;
      return Alert._jQueryInterface;
    };

    return Alert;

  }));

  });

  function _inheritsLoose(subClass, superClass) {
    subClass.prototype = Object.create(superClass.prototype);
    subClass.prototype.constructor = subClass;
    subClass.__proto__ = superClass;
  }

  function _createForOfIteratorHelperLoose(o, allowArrayLike) {
    var it;

    if (typeof Symbol === "undefined" || o[Symbol.iterator] == null) {
      if (Array.isArray(o) || (it = _unsupportedIterableToArray(o)) || allowArrayLike && o && typeof o.length === "number") {
        if (it) o = it;
        var i = 0;
        return function () {
          if (i >= o.length) return {
            done: true
          };
          return {
            done: false,
            value: o[i++]
          };
        };
      }

      throw new TypeError("Invalid attempt to iterate non-iterable instance.\nIn order to be iterable, non-array objects must have a [Symbol.iterator]() method.");
    }

    it = o[Symbol.iterator]();
    return it.next.bind(it);
  }

  var ob1Common = {};
  var breakpoints = {
    XSMALL: 320,
    SMALL: 480,
    MEDIUM: 736,
    LARGE: 960,
    XLARGE: 1200,
    XXLARGE: 1440
  };

  var refs = {};
  var instanceCount = 0;
  /**
   * Classe dont doivent hériter tous les composants OB1 pour normaliser le fonctionnement
   * En héritant de cette classe, on donne accès à de nouvelles propriétés :
   * - this.componentName : le nom du composant (le nom de la classe à partir de laquelle il est construit)
   * - this.ref : la référence du composant
   * - this.parameters : les paramètres d'instanciation (@see getDefaultParams(), _init() pour voir comment les paramètres sont construits)
   * - this.container : le noeud DOM à partir duquel le composant est construit (il y en a forcément un)
   *
   * On donne aussi accès à une fonction "bridge" rattachée au noeud DOM, qui permet de commander le composant.
   * Ex:
   * pour le composant FilterChipsBar, après l'instanciation du composant sur le noeud DOM node,
   * on a accès à node.FilterChipsBar pour accéder aux méthodes du composant :
   *
   * node.FilterChipsBar('METHOD_NAME', PARAMS)
   * comme : node.FilterChipsBar('onUpdateValues', function(details) {
          console.debug(details);
        });
   *
   */

  var Ob1Component = /*#__PURE__*/function () {
    /**
     * Construteur
     *
     * The constructor should only contain the boiler plate code for finding or creating the reference.
     *
     * @param {HTMLElement} container le container sur lequel est instancié le composant
     * @param {string} composantName le nom du composant
     * @param {object} parameters les paramètres d'instanciation
     * @return {*}
     */
    function Ob1Component(container, componentName, parameters) {
      this.componentName = componentName;

      if (container) {
        var refParamName = "ref" + this.componentName;

        if (typeof container.dataset[refParamName] === "undefined") {
          this.ref = "" + this.componentName + ++instanceCount;
          refs[this.ref] = this;
          container.dataset[refParamName] = this.ref;
          container[this.componentName] = this.execute.bind(this);
          this.init(container, parameters || {});
        } else {
          // If this element has already been instantiated, use the existing reference.
          return refs[container.dataset[refParamName]];
        }
      }
    }
    /**
     * Les paramètres par défaut du composant
     * Ils sont surchargés (par ordre de priorité) par :
     * - l'attribut data sur le noeud DOM du composant
     * - les paramètres utilisés au moment de l'instanciation
     * @returns {{}}
     */


    Ob1Component.getDefaultParams = function getDefaultParams() {
      return {};
    }
    /**
     * Charge les composants ob1 présents dans un noeud DOM (ou dans ses fils)
     * @param {HTMLElement} node le noeud DOM dans lequel on essaie de trouver des composants ob1 à charger
     */
    ;

    Ob1Component.load = function load(node) {
      node = node || document.body;
      var ob1ComponentNodes = node.querySelectorAll("[data-ob1-component]");
      [].forEach.call(ob1ComponentNodes, function (ob1ComponentNode) {
        var componentConstructorName = ob1ComponentNode.getAttribute("data-ob1-component");

        if (componentConstructorName) {
          var aComponentConstructorName = componentConstructorName.split(",").map(function (value) {
            return value.trim();
          });
          aComponentConstructorName.forEach(function (constructorName) {
            if (constructorName && window[constructorName]) {
              new window[constructorName](ob1ComponentNode, {});
            }
          });
        }
      });
    }
    /**
     * Retourne l'éventuel composant défini sur le noeud DOM
     * @param {HTMLElement} node le noeud DOM dont on veut récupérer le composant
     * @return {Object} la liste des composants associés au noeud DOM,
     *    la clé de chaque élément étant le nom du constructeur d'un Ob1Component
     */
    ;

    Ob1Component.get = function get(node) {
      var component = {};

      if (node) {
        var componentConstructorName = node.getAttribute("data-ob1-component");

        if (componentConstructorName) {
          var aComponentConstructorName = componentConstructorName.split(",").map(function (value) {
            return value.trim();
          });
          aComponentConstructorName.forEach(function (constructorName) {
            if (!component[constructorName]) {
              var refParamName = "ref" + constructorName;
              var ref = node.dataset[refParamName];

              if (ref) {
                component[constructorName] = refs[ref];
              }
            }
          });
        }
      }

      return component;
    }
    /**
     * Supprime les éléments génériques du composant
     */
    ;

    var _proto = Ob1Component.prototype;

    _proto.dispose = function dispose() {
      delete this.container[this.componentName];
      delete this.container.dataset["ref" + this.componentName];
      delete refs[this.ref];
    }
    /**
     * Initialisation du composant, pour toute la partie générique d'un composant ob1
     * @param {HTMLElement} container le noeud DOM sur lequel est instancié le composant
     * @param {object} parameters les paramètres d'instanciation du composant
     */
    ;

    _proto.init = function init(container, parameters) {
      /**
       * Le container principal du composant
       */
      this.container = container; // récupération des paramètres d'instanciation

      parameters = parameters || {};
      this.parameters = {};
      var defaultParams = this.constructor.getDefaultParams();

      for (var key in defaultParams) {
        if (defaultParams.hasOwnProperty(key)) {
          var type = typeof defaultParams[key];
          var dataSetParam = this.container.getAttribute("data-" + this.componentName.toLowerCase() + "-" + key);

          if (typeof dataSetParam !== "undefined") {
            this.parameters[key] = type === "boolean" ? dataSetParam === "true" : dataSetParam;
          } else if (parameters.hasOwnProperty(key)) {
            this.parameters[key] = type === "boolean" ? parameters[key] === "true" : parameters[key];
          } else {
            this.parameters[key] = defaultParams[key];
          }
        }
      }
    }
    /**
     * Execute, pour cette instance, la méthode passée en paramètre si elle existe, avec tous les paramètres suivants
     * @param {array} params les paramètres d'éxécution :
     * - le premier paramètre indique l'action à exécuter
     * - les paramètres suivants sont utilisés comme paramètre d'appel à la méthode appelée
     */
    ;

    _proto.execute = function execute() {
      for (var _len = arguments.length, params = new Array(_len), _key = 0; _key < _len; _key++) {
        params[_key] = arguments[_key];
      }

      if (params.length > 0) {
        var action = params.shift();

        if (this[action] && typeof this[action] == "function") {
          this[action].apply(this, params);
        } else {
          console.error("[" + this.componentName + "] " + action + " is not a function");
        }
      } else {
        console.error("[" + this.componentName + "] execute not enough parameters");
      }
    }
    /**
     * Retourne true si on est en mobile, false sinon
     * Pour cela, on se base sur la largeur de l'écran et les points de rupture d'ob1
     * @return {boolean}
     */
    ;

    _proto.isMobile = function isMobile() {
      return window.innerWidth < breakpoints.MEDIUM;
    };

    return Ob1Component;
  }();
  window.Ob1Component = Ob1Component; // autoinstanciation des composants sur le DOMcontentLoaded

  document.addEventListener("DOMContentLoaded", function () {
    Ob1Component.load(document.body);
  });

  var classes = {
    selected: "ob1-box-radio-selected"
  }; // la liste des sélecteurs que l'on utilise dans le code du composant

  var selector = {
    parent: ".ob1-box-radio",
    radio: "input[type=radio]"
  };
  /**
   * ------------------------------------------------------------------------
   * Class Definition
   * ------------------------------------------------------------------------
   */

  var BoxRadioList = /*#__PURE__*/function (_Ob1Component) {
    _inheritsLoose(BoxRadioList, _Ob1Component);

    function BoxRadioList(container, parameters) {
      return _Ob1Component.call(this, container, "BoxRadioList", parameters) || this;
    }
    /**
     * Initialisation du composant BoxRadioList
     *
     * @param {HTMLElement} container le noeud DOM sur lequel est instancié le composant
     * @param {object} parameters les paramètres de ce composant
     */


    var _proto = BoxRadioList.prototype;

    _proto.init = function init(container, parameters) {
      var _this = this;

      // on appelle la méthode d'initialisation d'Ob1Component (obligatoire)
      _Ob1Component.prototype.init.call(this, container, parameters);

      this.items = [];
      var radioBtn = this.container.querySelectorAll(selector.radio);
      [].forEach.call(radioBtn, function (item) {
        if (item.checked) {
          _this._addStyle(item);
        } else {
          _this._removeStyle(item);
        }

        _this.items.push(item);
      });

      this._addEvents();
    }
    /**
     * Gestion des événements sur le composant
     * @private
     */
    ;

    _proto._addEvents = function _addEvents() {
      var _this2 = this;

      this._onChange = function (event) {
        _this2.items.forEach(function (item) {
          if (item === event.target) {
            _this2._addStyle(item);
          } else {
            _this2._removeStyle(item);
          }
        });
      }; // un changement a eu lieu sur l'une des cases à cocher


      this.container.addEventListener("change", this._onChange);
    }
    /**
     * Rajouter les styles pour indiquer l'item parent sélectionné du radioButton
     * @param {HTMLElement} item le radiobutton
     * @private
     */
    ;

    _proto._addStyle = function _addStyle(item) {
      var parent = item.closest(selector.parent);

      if (parent) {
        parent.classList.add(classes.selected);
      }
    }
    /**
     * Supprimer les styles pour indiquer l'item parent sélectionné du radioButton
     * @param {HTMLElement} item le radiobutton
     * @private
     */
    ;

    _proto._removeStyle = function _removeStyle(item) {
      var parent = item.closest(selector.parent);

      if (parent) {
        parent.classList.remove(classes.selected);
      }
    }
    /**
     * Décharge le composant
     */
    ;

    _proto.dispose = function dispose() {
      // suppression de tous les event listeners qui ont été créés
      this.container.removeEventListener("change", this._onChange); // on appelle la méthode de suppression de composant d'Ob1Component (obligatoire)

      _Ob1Component.prototype.dispose.call(this);
    };

    return BoxRadioList;
  }(Ob1Component); // rattachement au contexte window pour pouvoir l'utiliser en dehors du JS


  window.BoxRadioList = BoxRadioList;

  var selector$1 = {
    item: ".breadcrumb-item"
  };

  var Breadcrumb = /*#__PURE__*/function (_Ob1Component) {
    _inheritsLoose(Breadcrumb, _Ob1Component);

    function Breadcrumb(container, parameters) {
      return _Ob1Component.call(this, container, "Breadcrumb", parameters) || this;
    }
    /**
     * Initialisation du composant fil d'Ariane
     *
     * @param {HTMLElement} container le noeud DOM sur lequel est instancié le composant
     * @param {object} parameters les paramètres de ce composant
     */


    var _proto = Breadcrumb.prototype;

    _proto.init = function init(container, parameters) {
      _Ob1Component.prototype.init.call(this, container, parameters);

      this._addEvents();

      this.resize();
    }
    /**
     * Gestion des événements sur le composant
     * @private
     */
    ;

    _proto._addEvents = function _addEvents() {
      var _this = this;

      this._hOnResize = function () {
        clearTimeout(_this.resizetimeout);
        _this.resizetimeout = setTimeout(function () {
          _this.resize();
        }, 50);
      };

      window.addEventListener("resize", this._hOnResize);
    }
    /**
     * Redimensionnement du fil d'Ariane en fonction de la place disponible
     */
    ;

    _proto.resize = function resize() {
      var breadcrumbItem = this.container.querySelectorAll(selector$1.item); // on réaffiche tous les éléments du fil d'Ariane

      [].forEach.call(breadcrumbItem, function (item) {
        item.classList.remove("sr-only");
      }); // calcul de la largeur maximale du container

      var containerSize = this.container.offsetWidth; // on commence par le dernier élément car le fil d'Ariane affiche en priorité les éléments les plus profonds

      for (var i = breadcrumbItem.length - 1; i >= 0; i--) {
        var item = breadcrumbItem[i];
        containerSize -= item.offsetWidth;

        if (containerSize < 0) {
          // cet élément est trop grand, donc on le masque
          item.classList.add("sr-only");
        }
      }
    }
    /**
     * Décharge le composant
     */
    ;

    _proto.dispose = function dispose() {
      // suppression de l'event listener qui a été créé
      window.removeEventListener("resize", this._hOnResize); // on appelle la méthode de suppression de composant d'Ob1Component (obligatoire)

      _Ob1Component.prototype.dispose.call(this);
    };

    return Breadcrumb;
  }(Ob1Component);

  Breadcrumb.refs = {}; // rattachement au contexte window pour pouvoir l'utiliser en dehors du JS

  window.Breadcrumb = Breadcrumb;

  var button = createCommonjsModule(function (module, exports) {
  /*!
    * Boosted v4.3.1 (https://boosted.orange.com)
    * Copyright 2014-2019 The Boosted Authors
    * Copyright 2014-2019 Orange
    * Licensed under MIT (https://github.com/orange-opensource/orange-boosted-bootstrap/blob/master/LICENSE)
    * This a fork of Bootstrap : Initial license below
    * Bootstrap button.js v4.3.1 (https://boosted.orange.com)
    * Copyright 2011-2019 The Boosted Authors (https://github.com/Orange-OpenSource/Orange-Boosted-Bootstrap/graphs/contributors)
    * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
    */
  (function (global, factory) {
     module.exports = factory(jquery) ;
  }(commonjsGlobal, function ($) {
    $ = $ && $.hasOwnProperty('default') ? $['default'] : $;

    function _defineProperties(target, props) {
      for (var i = 0; i < props.length; i++) {
        var descriptor = props[i];
        descriptor.enumerable = descriptor.enumerable || false;
        descriptor.configurable = true;
        if ("value" in descriptor) descriptor.writable = true;
        Object.defineProperty(target, descriptor.key, descriptor);
      }
    }

    function _createClass(Constructor, protoProps, staticProps) {
      if (protoProps) _defineProperties(Constructor.prototype, protoProps);
      if (staticProps) _defineProperties(Constructor, staticProps);
      return Constructor;
    }

    /**
     * ------------------------------------------------------------------------
     * Constants
     * ------------------------------------------------------------------------
     */

    var NAME = 'button';
    var VERSION = '4.3.1';
    var DATA_KEY = 'bs.button';
    var EVENT_KEY = "." + DATA_KEY;
    var DATA_API_KEY = '.data-api';
    var JQUERY_NO_CONFLICT = $.fn[NAME];
    var ClassName = {
      ACTIVE: 'active',
      BUTTON: 'btn',
      FOCUS: 'focus'
    };
    var Selector = {
      DATA_TOGGLE_CARROT: '[data-toggle^="button"]',
      DATA_TOGGLE: '[data-toggle="buttons"]',
      INPUT: 'input:not([type="hidden"])',
      ACTIVE: '.active',
      BUTTON: '.btn'
    };
    var Event = {
      CLICK_DATA_API: "click" + EVENT_KEY + DATA_API_KEY,
      FOCUS_BLUR_DATA_API: "focus" + EVENT_KEY + DATA_API_KEY + " " + ("blur" + EVENT_KEY + DATA_API_KEY)
      /**
       * ------------------------------------------------------------------------
       * Class Definition
       * ------------------------------------------------------------------------
       */

    };

    var Button =
    /*#__PURE__*/
    function () {
      function Button(element) {
        this._element = element;
      } // Getters


      var _proto = Button.prototype;

      // Public
      _proto.toggle = function toggle() {
        var rootElement = $(this._element).closest(Selector.DATA_TOGGLE)[0];

        var input = this._element.querySelector(Selector.INPUT);

        if (rootElement) {
          var activeElement = rootElement.querySelector(Selector.ACTIVE);

          if (activeElement) {
            activeElement.classList.remove(ClassName.ACTIVE);
          }
        }

        if (input) {
          if (input.checked) {
            this._element.classList.add(ClassName.ACTIVE);
          } else {
            this._element.classList.remove(ClassName.ACTIVE);
          }
        } else {
          this._element.classList.toggle(ClassName.ACTIVE);

          this._element.setAttribute('aria-pressed', this._element.classList.contains(ClassName.ACTIVE));
        }
      };

      _proto.dispose = function dispose() {
        $.removeData(this._element, DATA_KEY);
        this._element = null;
      } // Static
      ;

      Button._jQueryInterface = function _jQueryInterface(config) {
        return this.each(function () {
          var data = $(this).data(DATA_KEY);

          if (!data) {
            data = new Button(this);
            $(this).data(DATA_KEY, data);
          }

          if (config === 'toggle') {
            data[config]();
          }
        });
      };

      _createClass(Button, null, [{
        key: "VERSION",
        get: function get() {
          return VERSION;
        }
      }]);

      return Button;
    }();
    /**
     * ------------------------------------------------------------------------
     * Data Api implementation
     * ------------------------------------------------------------------------
     */


    $(document).on(Event.CLICK_DATA_API, Selector.DATA_TOGGLE_CARROT, function (event) {
      var button = event.target;

      if (!$(button).hasClass(ClassName.BUTTON)) {
        button = $(button).closest(Selector.BUTTON);
      }

      Button._jQueryInterface.call($(button), 'toggle');
    }).on(Event.FOCUS_BLUR_DATA_API, Selector.DATA_TOGGLE_CARROT, function (event) {
      var button = $(event.target).closest(Selector.BUTTON)[0];

      if (button) {
        $(button).toggleClass(ClassName.FOCUS, /^focus(in)?$/.test(event.type));
      }
    }).on(Event.FOCUS_BLUR_DATA_API, Selector.DATA_TOGGLE_CARROT > Selector.INPUT, function (event) {
      var button = $(event.target).closest(Selector.BUTTON)[0];

      if (button) {
        $(button).toggleClass(ClassName.FOCUS, /^focus(in)?$/.test(event.type));
      }
    });
    /**
     * ------------------------------------------------------------------------
     * jQuery
     * ------------------------------------------------------------------------
     */

    $.fn[NAME] = Button._jQueryInterface;
    $.fn[NAME].Constructor = Button;

    $.fn[NAME].noConflict = function () {
      $.fn[NAME] = JQUERY_NO_CONFLICT;
      return Button._jQueryInterface;
    };

    return Button;

  }));

  });

  var carrouselClasses = {
    carrousel: "ob1-carrousel",
    pagination: "swiper-pagination",
    next: "swiper-button-next",
    prev: "swiper-button-prev",
    controls: "ob1-carrousel-controls",
    play: "ob1-carrousel-controls-play",
    page_indicator_item: "ob1-page-indicator-item",
    page_indicator_active: "ob1-page-indicator-active",
    slide: "swiper-slide"
  };
  var carrouselAttributes = {
    slide_index: "data-swiper-slide-index"
  };
  var carrouselTexts = {
    pause: "Mettre en pause le carrousel",
    play: "Reprendre la lecture du carrousel"
  };

  var Carrousel = /*#__PURE__*/function () {
    function Carrousel(carrouselEl, autoplay) {
      if (autoplay === void 0) {
        autoplay = true;
      }

      if (typeof carrouselEl.swiper !== "object") {
        this.config = {
          a11y: {
            enabled: false
          },
          loop: true,
          keyboard: {
            enabled: true,
            onlyInViewport: false
          },
          pagination: {
            el: "." + carrouselClasses.pagination,
            clickable: true,
            type: "bullets",
            bulletClass: carrouselClasses.page_indicator_item,
            bulletActiveClass: carrouselClasses.page_indicator_active,
            renderBullet: function renderBullet(index, className) {
              return "<li class=\"" + className + "\">" + "<button class=\"ob1-page-indicator-button\" type=\"button\" tabindex=\"-1\"></button>" + "</li>";
            }
          },
          navigation: {
            nextEl: "." + carrouselClasses.next,
            prevEl: "." + carrouselClasses.prev
          },
          observer: true,
          observeParents: true,
          on: {
            init: function init() {
              Array.from(document.querySelectorAll(".swiper-slide-duplicate")).forEach(function (duplicateSlide) {
                duplicateSlide.setAttribute("tabindex", -1);
                duplicateSlide.setAttribute("aria-hidden", true);
              });
            }
          }
        };

        if (autoplay) {
          this.config.autoplay = {
            delay: 6000,
            disableOnInteraction: false
          };
        }

        this.carrouselEl = carrouselEl;
        new Swiper(carrouselEl, this.config);

        if (autoplay) {
          this.controlsListener();
        }

        this.slideToOnFocus(autoplay);
      }
    }
    /**
     * Le bouton "pause" étant un composant personnalisé, cette fonction permet d'ajouter les écouteurs nécessaires au
     * contrôle du carrousel
     */


    var _proto = Carrousel.prototype;

    _proto.controlsListener = function controlsListener() {
      var _this = this;

      this._onClick = function (control) {
        if (_this.carrouselEl.swiper.autoplay.running) {
          _this.carrouselEl.swiper.autoplay.stop();

          control.setAttribute("title", carrouselTexts.play);
          control.setAttribute("aria-label", carrouselTexts.play);
          control.classList.add(carrouselClasses.play);
          control.children[0].classList.remove("icon-Pause");
          control.children[0].classList.add("icon-Play");
          control.children[1].textContent = "Lecture";
        } else {
          _this.carrouselEl.swiper.autoplay.start();

          control.setAttribute("title", carrouselTexts.pause);
          control.setAttribute("aria-label", carrouselTexts.pause);
          control.classList.remove(carrouselClasses.play);
          control.children[0].classList.remove("icon-Play");
          control.children[0].classList.add("icon-Pause");
          control.children[1].textContent = "Pause";
        }
      };

      var control = this.carrouselEl.querySelector("." + carrouselClasses.controls);
      this._onClickControl = this._onClick.bind(this, control);
      control.addEventListener("click", this._onClickControl);
    }
    /**
     * Gestion du focus des slides, chaque slide est focusable, on déplace le slide active pour qu'il soit visible puis
     * on stoppe l'autoplay. Quand on perds le focus, on relance l'autoplay.
     */
    ;

    _proto.slideToOnFocus = function slideToOnFocus(autoplay) {
      var _this2 = this;

      this._onFocus = function (slide) {
        slide.closest("." + carrouselClasses.carrousel).scrollLeft = 0;
        var slideIndex = parseInt(slide.getAttribute(carrouselAttributes.slide_index));

        _this2.carrouselEl.swiper.autoplay.stop();

        _this2.carrouselEl.swiper.slideToLoop(slideIndex);
      };

      this._onBlur = function () {
        _this2.carrouselEl.swiper.autoplay.start();
      };

      this._onFocuses = [];
      Array.from(this.carrouselEl.querySelectorAll("." + carrouselClasses.slide)).forEach(function (slide, index) {
        _this2._onFocuses[index] = _this2._onFocus.bind(_this2, slide);
        slide.addEventListener("focus", _this2._onFocuses[index]);

        if (autoplay) {
          slide.addEventListener("blur", _this2._onBlur);
        }
      });
    }
    /**
     * Décharge le composant
     */
    ;

    _proto.dispose = function dispose() {
      var _this3 = this;

      // suppression de tous les event listeners qui ont été créés
      var control = this.carrouselEl.querySelector("." + carrouselClasses.controls);
      control.removeEventListener("click", this._onClickControl);
      Array.from(this.carrouselEl.querySelectorAll("." + carrouselClasses.slide)).forEach(function (slide, index) {
        slide.removeEventListener("focus", _this3._onFocuses[index]);

        if (autoplay) {
          slide.removeEventListener("blur", _this3._onBlur);
        }
      });
    };

    return Carrousel;
  }();

  document.addEventListener("DOMContentLoaded", function () {
    Array.from(document.querySelectorAll(".ob1-carrousel")).forEach(function (carrousel) {
      new Carrousel(carrousel);
    });
  }); // rattachement au contexte window pour pouvoir l'utiliser en dehors du JS

  window.Carrousel = Carrousel;

  var collapse = createCommonjsModule(function (module, exports) {
  /*!
    * Boosted v4.3.1 (https://boosted.orange.com)
    * Copyright 2014-2019 The Boosted Authors
    * Copyright 2014-2019 Orange
    * Licensed under MIT (https://github.com/orange-opensource/orange-boosted-bootstrap/blob/master/LICENSE)
    * This a fork of Bootstrap : Initial license below
    * Bootstrap collapse.js v4.3.1 (https://boosted.orange.com)
    * Copyright 2011-2019 The Boosted Authors (https://github.com/Orange-OpenSource/Orange-Boosted-Bootstrap/graphs/contributors)
    * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
    */
  (function (global, factory) {
     module.exports = factory(jquery, util) ;
  }(commonjsGlobal, function ($, Util) {
    $ = $ && $.hasOwnProperty('default') ? $['default'] : $;
    Util = Util && Util.hasOwnProperty('default') ? Util['default'] : Util;

    function _defineProperties(target, props) {
      for (var i = 0; i < props.length; i++) {
        var descriptor = props[i];
        descriptor.enumerable = descriptor.enumerable || false;
        descriptor.configurable = true;
        if ("value" in descriptor) descriptor.writable = true;
        Object.defineProperty(target, descriptor.key, descriptor);
      }
    }

    function _createClass(Constructor, protoProps, staticProps) {
      if (protoProps) _defineProperties(Constructor.prototype, protoProps);
      if (staticProps) _defineProperties(Constructor, staticProps);
      return Constructor;
    }

    function _defineProperty(obj, key, value) {
      if (key in obj) {
        Object.defineProperty(obj, key, {
          value: value,
          enumerable: true,
          configurable: true,
          writable: true
        });
      } else {
        obj[key] = value;
      }

      return obj;
    }

    function _objectSpread(target) {
      for (var i = 1; i < arguments.length; i++) {
        var source = arguments[i] != null ? arguments[i] : {};
        var ownKeys = Object.keys(source);

        if (typeof Object.getOwnPropertySymbols === 'function') {
          ownKeys = ownKeys.concat(Object.getOwnPropertySymbols(source).filter(function (sym) {
            return Object.getOwnPropertyDescriptor(source, sym).enumerable;
          }));
        }

        ownKeys.forEach(function (key) {
          _defineProperty(target, key, source[key]);
        });
      }

      return target;
    }

    /**
     * ------------------------------------------------------------------------
     * Constants
     * ------------------------------------------------------------------------
     */

    var NAME = 'collapse';
    var VERSION = '4.3.1';
    var DATA_KEY = 'bs.collapse';
    var EVENT_KEY = "." + DATA_KEY;
    var DATA_API_KEY = '.data-api';
    var JQUERY_NO_CONFLICT = $.fn[NAME];
    var Default = {
      toggle: true,
      parent: ''
    };
    var DefaultType = {
      toggle: 'boolean',
      parent: '(string|element)'
    };
    var Event = {
      SHOW: "show" + EVENT_KEY,
      SHOWN: "shown" + EVENT_KEY,
      HIDE: "hide" + EVENT_KEY,
      HIDDEN: "hidden" + EVENT_KEY,
      CLICK_DATA_API: "click" + EVENT_KEY + DATA_API_KEY
    };
    var ClassName = {
      SHOW: 'show',
      COLLAPSE: 'collapse',
      COLLAPSING: 'collapsing',
      COLLAPSED: 'collapsed'
    };
    var Dimension = {
      WIDTH: 'width',
      HEIGHT: 'height'
    };
    var Selector = {
      ACTIVES: '*:not(.multi) > .show, *:not(.multi) > .collapsing',
      // boosted mod
      DATA_TOGGLE: '[data-toggle="collapse"]'
      /**
       * ------------------------------------------------------------------------
       * Class Definition
       * ------------------------------------------------------------------------
       */

    };

    var Collapse =
    /*#__PURE__*/
    function () {
      function Collapse(element, config) {
        this._isTransitioning = false;
        this._element = element;
        this._config = this._getConfig(config);
        this._triggerArray = [].slice.call(document.querySelectorAll("[data-toggle=\"collapse\"][href=\"#" + element.id + "\"]," + ("[data-toggle=\"collapse\"][data-target=\"#" + element.id + "\"]")));
        var toggleList = [].slice.call(document.querySelectorAll(Selector.DATA_TOGGLE));

        for (var i = 0, len = toggleList.length; i < len; i++) {
          var elem = toggleList[i];
          var selector = Util.getSelectorFromElement(elem);
          var filterElement = [].slice.call(document.querySelectorAll(selector)).filter(function (foundElem) {
            return foundElem === element;
          });

          if (selector !== null && filterElement.length > 0) {
            this._selector = selector;

            this._triggerArray.push(elem);
          }
        }

        this._parent = this._config.parent ? this._getParent() : null;

        if (!this._config.parent) {
          this._addAriaAndCollapsedClass(this._element, this._triggerArray);
        }

        if (this._config.toggle) {
          this.toggle();
        }
      } // Getters


      var _proto = Collapse.prototype;

      // Public
      _proto.toggle = function toggle() {
        if ($(this._element).hasClass(ClassName.SHOW)) {
          this.hide();
        } else {
          this.show();
        }
      };

      _proto.show = function show() {
        var _this = this;

        if (this._isTransitioning || $(this._element).hasClass(ClassName.SHOW)) {
          return;
        }

        var actives;
        var activesData;

        if (this._parent) {
          actives = [].slice.call(this._parent.querySelectorAll(Selector.ACTIVES)).filter(function (elem) {
            if (typeof _this._config.parent === 'string') {
              return elem.getAttribute('data-parent') === _this._config.parent;
            }

            return elem.classList.contains(ClassName.COLLAPSE);
          });

          if (actives.length === 0) {
            actives = null;
          }
        }

        if (actives) {
          activesData = $(actives).not(this._selector).data(DATA_KEY);

          if (activesData && activesData._isTransitioning) {
            return;
          }
        }

        var startEvent = $.Event(Event.SHOW);
        $(this._element).trigger(startEvent);

        if (startEvent.isDefaultPrevented()) {
          return;
        }

        if (actives) {
          Collapse._jQueryInterface.call($(actives).not(this._selector), 'hide');

          if (!activesData) {
            $(actives).data(DATA_KEY, null);
          }
        }

        var dimension = this._getDimension();

        $(this._element).removeClass(ClassName.COLLAPSE).addClass(ClassName.COLLAPSING);
        this._element.style[dimension] = 0;

        if (this._triggerArray.length) {
          $(this._triggerArray).removeClass(ClassName.COLLAPSED).attr('aria-expanded', true);
        }

        this.setTransitioning(true);

        var complete = function complete() {
          $(_this._element).removeClass(ClassName.COLLAPSING).addClass(ClassName.COLLAPSE).addClass(ClassName.SHOW);
          _this._element.style[dimension] = '';

          _this.setTransitioning(false);

          $(_this._element).trigger(Event.SHOWN);
        };

        var capitalizedDimension = dimension[0].toUpperCase() + dimension.slice(1);
        var scrollSize = "scroll" + capitalizedDimension;
        var transitionDuration = Util.getTransitionDurationFromElement(this._element);
        $(this._element).one(Util.TRANSITION_END, complete).emulateTransitionEnd(transitionDuration);
        this._element.style[dimension] = this._element[scrollSize] + "px";
      };

      _proto.hide = function hide() {
        var _this2 = this;

        if (this._isTransitioning || !$(this._element).hasClass(ClassName.SHOW)) {
          return;
        }

        var startEvent = $.Event(Event.HIDE);
        $(this._element).trigger(startEvent);

        if (startEvent.isDefaultPrevented()) {
          return;
        }

        var dimension = this._getDimension();

        this._element.style[dimension] = this._element.getBoundingClientRect()[dimension] + "px";
        Util.reflow(this._element);
        $(this._element).addClass(ClassName.COLLAPSING).removeClass(ClassName.COLLAPSE).removeClass(ClassName.SHOW);
        var triggerArrayLength = this._triggerArray.length;

        if (triggerArrayLength > 0) {
          for (var i = 0; i < triggerArrayLength; i++) {
            var trigger = this._triggerArray[i];
            var selector = Util.getSelectorFromElement(trigger);

            if (selector !== null) {
              var $elem = $([].slice.call(document.querySelectorAll(selector)));

              if (!$elem.hasClass(ClassName.SHOW)) {
                $(trigger).addClass(ClassName.COLLAPSED).attr('aria-expanded', false);
              }
            }
          }
        }

        this.setTransitioning(true);

        var complete = function complete() {
          _this2.setTransitioning(false);

          $(_this2._element).removeClass(ClassName.COLLAPSING).addClass(ClassName.COLLAPSE).trigger(Event.HIDDEN);
        };

        this._element.style[dimension] = '';
        var transitionDuration = Util.getTransitionDurationFromElement(this._element);
        $(this._element).one(Util.TRANSITION_END, complete).emulateTransitionEnd(transitionDuration);
      };

      _proto.setTransitioning = function setTransitioning(isTransitioning) {
        this._isTransitioning = isTransitioning;
      };

      _proto.dispose = function dispose() {
        $.removeData(this._element, DATA_KEY);
        this._config = null;
        this._parent = null;
        this._element = null;
        this._triggerArray = null;
        this._isTransitioning = null;
      } // Private
      ;

      _proto._getConfig = function _getConfig(config) {
        config = _objectSpread({}, Default, config);
        config.toggle = Boolean(config.toggle); // Coerce string values

        Util.typeCheckConfig(NAME, config, DefaultType);
        return config;
      };

      _proto._getDimension = function _getDimension() {
        var hasWidth = $(this._element).hasClass(Dimension.WIDTH);
        return hasWidth ? Dimension.WIDTH : Dimension.HEIGHT;
      };

      _proto._getParent = function _getParent() {
        var _this3 = this;

        var parent;

        if (Util.isElement(this._config.parent)) {
          parent = this._config.parent; // It's a jQuery object

          if (typeof this._config.parent.jquery !== 'undefined') {
            parent = this._config.parent[0];
          }
        } else {
          parent = document.querySelector(this._config.parent);
        }

        var selector = "[data-toggle=\"collapse\"][data-parent=\"" + this._config.parent + "\"]";
        var children = [].slice.call(parent.querySelectorAll(selector));
        $(children).each(function (i, element) {
          _this3._addAriaAndCollapsedClass(Collapse._getTargetFromElement(element), [element]);
        });
        return parent;
      };

      _proto._addAriaAndCollapsedClass = function _addAriaAndCollapsedClass(element, triggerArray) {
        var isOpen = $(element).hasClass(ClassName.SHOW);

        if (triggerArray.length) {
          $(triggerArray).toggleClass(ClassName.COLLAPSED, !isOpen).attr('aria-expanded', isOpen);
        }
      } // Static
      ;

      Collapse._getTargetFromElement = function _getTargetFromElement(element) {
        var selector = Util.getSelectorFromElement(element);
        return selector ? document.querySelector(selector) : null;
      };

      Collapse._jQueryInterface = function _jQueryInterface(config) {
        return this.each(function () {
          var $this = $(this);
          var data = $this.data(DATA_KEY);

          var _config = _objectSpread({}, Default, $this.data(), typeof config === 'object' && config ? config : {});

          if (!data && _config.toggle && /show|hide|init/.test(config)) {
            // Boosted mod
            _config.toggle = false;
          }

          if (!data) {
            data = new Collapse(this, _config);
            $this.data(DATA_KEY, data);
          } // Boosted mod


          if (/init/.test(config)) {
            return;
          } // end mod


          if (typeof config === 'string') {
            if (typeof data[config] === 'undefined') {
              throw new TypeError("No method named \"" + config + "\"");
            }

            data[config]();
          }
        });
      };

      _createClass(Collapse, null, [{
        key: "VERSION",
        get: function get() {
          return VERSION;
        }
      }, {
        key: "Default",
        get: function get() {
          return Default;
        }
      }]);

      return Collapse;
    }();
    /**
     * ------------------------------------------------------------------------
     * Data Api implementation
     * ------------------------------------------------------------------------
     */


    $(document).on(Event.CLICK_DATA_API, Selector.DATA_TOGGLE, function (event) {
      // preventDefault only for <a> elements (which change the URL) not inside the collapsible element
      if (event.currentTarget.tagName === 'A') {
        event.preventDefault();
      }

      var $trigger = $(this);
      var selector = Util.getSelectorFromElement(this);
      var selectors = [].slice.call(document.querySelectorAll(selector));
      $(selectors).each(function () {
        var $target = $(this);
        var data = $target.data(DATA_KEY);
        var config = data ? 'toggle' : $trigger.data();

        Collapse._jQueryInterface.call($target, config);
      });
    }) // Boosted mod
    .on('DOMContentLoaded', function () {
      $(Selector.DATA_TOGGLE).each(function () {
        var target = Collapse._getTargetFromElement(this);

        Collapse._jQueryInterface.call($(target), 'init');
      });
    }); // end mod

    /**
     * ------------------------------------------------------------------------
     * jQuery
     * ------------------------------------------------------------------------
     */

    $.fn[NAME] = Collapse._jQueryInterface;
    $.fn[NAME].Constructor = Collapse;

    $.fn[NAME].noConflict = function () {
      $.fn[NAME] = JQUERY_NO_CONFLICT;
      return Collapse._jQueryInterface;
    };

    return Collapse;

  }));

  });

  var DatePicker = /*#__PURE__*/function () {
    var _proto = DatePicker.prototype;

    /**
     * Initialisation du Date Picker
     */
    _proto.init = function init(container, dates, mobileModeDisabled) {
      this.container = container; // Au chargement, test d'affichage de la version du Date Picker, mobile ou desktop

      this.changeDisplayMode(dates, mobileModeDisabled);

      this._addEvents(dates, mobileModeDisabled);
    }
    /**
     * Gestion des événements sur le composant
     * @private
     */
    ;

    _proto._addEvents = function _addEvents(dates, mobileModeDisabled) {
      var _this = this;

      // gestion de l'évenement resize du navigateur pour choix affichage du Date Picker mobile ou desktop
      this._onResize = function () {
        _this.changeDisplayMode(dates, mobileModeDisabled);
      };

      window.addEventListener("resize", this._onResize); // Gestion des écouteurs

      this._onClick = function (event) {
        if (event.target.classList.contains("changeDatePickerSize")) {
          _this.changeDatePickerSize(mobileModeDisabled);
        } // On monte le date picker de 2px pour cacher la bordure de l'input et éviter le double liseret


        var topVal = parseInt(document.getElementById("ui-datepicker-div").style.top, 10);
        document.getElementById("ui-datepicker-div").style.top = topVal - 2 + "px";
      };

      this.container.addEventListener("click", this._onClick);
    } // affichage ou masquage du datepicker Desktop en fonction de la résolution
    ;

    _proto.changeDisplayMode = function changeDisplayMode(dates, mobileModeDisabled) {
      var selectedDate = this.container.querySelector(".inputDatePicker").value;
      var windowWidth = document.documentElement.clientWidth;

      if (windowWidth >= breakpoints.MEDIUM || mobileModeDisabled) {
        // Changement du type de date picker en desktop
        this.container.querySelector(".inputDatePicker").type = "text";

        if (!this.container.querySelector(".icon-calendar-day")) {
          var iconEl = document.createElement("span");
          iconEl.classList.add("icon", "icon-calendar-day");
          iconEl.setAttribute("aria-hidden", "true");
          this.container.querySelector(".labelDatePicker").parentNode.insertBefore(iconEl, this.container.querySelector(".labelDatePicker").nextSibling);
        } // Paramétrage du datepicker Desktop


        $(this.container.querySelector(".inputDatePicker")).datepicker({
          closeText: "Fermer",
          prevText: "Précédent",
          nextText: "Suivant",
          currentText: "Aujourd'hui",
          monthNames: ["Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet", "Août", "Septembre", "Octobre", "Novembre", "Décembre"],
          monthNamesShort: ["janv.", "févr.", "mars", "avr.", "mai", "juin", "juil.", "août", "sept.", "oct.", "nov.", "déc."],
          dayNames: ["dimanche", "lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi"],
          dayNamesShort: ["dim.", "lun.", "mar.", "mer.", "jeu.", "ven.", "sam."],
          dayNamesMin: ["Di", "Lu", "Ma", "Me", "Je", "Ve", "Sa"],
          weekHeader: "Sem.",
          dateFormat: "dd/mm/yy",
          // fonction pour modifier la largeur du Date Picker Desktop à X mois
          onChangeMonthYear: function onChangeMonthYear() {
            var datepickerDiv = document.getElementById("ui-datepicker-div");
            datepickerDiv.style.setProperty("font-size", "1.2em");
          },
          // fonction pour mettre à jour l'affichage du champs une fois la date sélectionnée
          onSelect: function onSelect() {
            this.classList.remove("form-control-empty");
          },
          beforeShowDay: this._beforeShowDay(dates),
          firstDay: 1,
          isRTL: false,
          showMonthAfterYear: false,
          yearSuffix: "",
          numberOfMonths: windowWidth < breakpoints.MEDIUM && mobileModeDisabled ? 1 : 2,
          minDate: new Date(),
          maxDate: "+1y",
          showButtonPanel: false
        }); // si changement de résolution, on récupère date sélectionnée dans Date Picker Mobile pour alimenter dans Date Picker Desktop

        var smallSelectedDate = selectedDate.split("-").reverse().join("/");
        $(this.container.querySelector(".inputDatePicker")).datepicker("setDate", smallSelectedDate);
      } else {
        // Changement du type de date picker en mobile
        this.container.querySelector(".inputDatePicker").type = "date";

        if (this.container.querySelector(".icon-calendar-day")) {
          this.container.querySelector(".icon-calendar-day").remove();
        } // fonction pour mettre à jour la date du Date Picker Mobile à partir de la sélection du Date Picker Desktop


        var bigSelectedDate = selectedDate.split("/").reverse().join("-");
        this.container.querySelector(".inputDatePicker").value = bigSelectedDate;
      }
    } // fonction pour modifier la largeur du Date Picker Desktop à X mois
    ;

    _proto.changeDatePickerSize = function changeDatePickerSize(mobileModeDisabled) {
      var datepickerDiv = document.getElementById("ui-datepicker-div");
      datepickerDiv.style.setProperty("font-size", "1.2em"); // Masquage de la DIV date Picker en mobile

      var windowWidth = document.documentElement.clientWidth;

      if (windowWidth < breakpoints.MEDIUM && !mobileModeDisabled) {
        document.getElementById("ui-datepicker-div").style.display = "none";
      }
    }
    /**
     * Détermine une liste de dates prédéfinies
     *
     * @param {*} dates  tableau de dates prédéfinies au format "yy-mm-dd"
     */
    ;

    _proto.changeSelectableDates = function changeSelectableDates(dates) {
      $(this.container.querySelector(".inputDatePicker")).datepicker("option", "beforeShowDay", this._beforeShowDay(dates));
    };

    _proto._beforeShowDay = function _beforeShowDay(dates) {
      return function (date) {
        var dateWhitoutHours = jQuery.datepicker.formatDate("yy-mm-dd", date);

        if (dates.length > 0) {
          return [dates.indexOf(dateWhitoutHours) !== -1];
        } else {
          return dateWhitoutHours;
        }
      };
    }
    /**
     * Constructeur du Date Picker
     */
    ;

    function DatePicker(container, dates, mobileModeDisabled) {
      if (dates === void 0) {
        dates = [];
      }

      if (mobileModeDisabled === void 0) {
        mobileModeDisabled = false;
      }

      if (container) {
        if (typeof container.dataset.ref === "undefined") {
          this.ref = Math.random();
          DatePicker.refs[this.ref] = this;
          container.dataset.ref = this.ref;
          this.init(container, dates, mobileModeDisabled);
        } else {
          // If this element has already been instantiated, use the existing reference.
          return DatePicker.refs[container.dataset.ref];
        }
      }
    }
    /**
     * Décharge le composant
     */


    _proto.dispose = function dispose() {
      window.removeEventListener("resize", this._onResize);
      this.container.removeEventListener("click", this._onClick);
    };

    return DatePicker;
  }();

  DatePicker.refs = {};
  document.addEventListener("DOMContentLoaded", function () {
    var datepickers = document.querySelectorAll(".date-picker");
    [].forEach.call(datepickers, function (datepicker) {
      new DatePicker(datepicker);
    });
  }); // rattachement au contexte window pour pouvoir l'utiliser en dehors du JS

  window.DatePicker = DatePicker;

  var DateTimePicker = /*#__PURE__*/function () {
    var _proto = DateTimePicker.prototype;

    /**
     * Initialisation du Date Time Picker
     */
    _proto.init = function init(container, proposals) {
      var _this = this;

      this.container = container;
      this.listOfValidDates = proposals;

      if (!this.listOfValidDates) {
        return;
      } // configuration des parametres pour pouvoir generer le code html des differents slides


      var datesOptions = {
        weekday: "long",
        month: "short",
        day: "2-digit"
      }; // configuration du nombre d'éléments par slide selon la taille de l'écran

      var componentWidth = this.container.offsetWidth;
      var nbItemsPerSlide = 1; // version plages horaires

      if (this.container.classList.contains("ob1-date-time-picker-slots")) {
        if (componentWidth >= 960) {
          // Extra large et XX large
          nbItemsPerSlide = 7;
        } else if (componentWidth >= 736) {
          // Large
          nbItemsPerSlide = 5;
        } else if (componentWidth >= 480) {
          // Medium
          nbItemsPerSlide = 4;
        } // version horaires fixes

      } else {
        if (componentWidth >= 736) {
          // Large, Extra large et XX large
          nbItemsPerSlide = 7;
        } else if (componentWidth >= 480) {
          // Medium
          nbItemsPerSlide = 5;
        }
      }

      var nbDateTimeItems = proposals.datesTimes.length;
      var K = 0;
      var slideIndex = 0;
      var itemString = "";
      var nbTimeSlotsMax = proposals.datesTimes.reduce(function (accumulator, currentValue) {
        return Math.max(accumulator, Object.keys(currentValue.hourProposals).length);
      }, 0); // en-tete du swiper

      itemString += "<div class=\"swiper-container\">\n      <div class=\"swiper-wrapper d-flex swiper-content mb-0\">"; // on boucle X fois sur la liste des dates en fonction du nombre de dates souhaitees par slides

      while (K < nbDateTimeItems) {
        K = K + nbItemsPerSlide; // conteneur de chaque slide

        itemString += "<div class=\"swiper-slide w-100 pt-2 pt-md-0 swiper-item\" id=\"slide" + slideIndex + "\">\n              <div class=\"d-flex justify-content-between\">\n                <div class=\"ob1-date-time-picker-arrow\"></div>";
        slideIndex++; // pour chaque slide, on affiche les X dates correspondantes

        for (var i = K - nbItemsPerSlide; i < K; i++) {
          var entry = proposals.datesTimes[i];

          if (entry != null) {
            var entryDate = new Date(entry.dateProposals).toLocaleDateString("fr-FR", datesOptions);
            var dateElts = entryDate.split(" ");
            entryDate = dateElts[0] + " " + "<br class='d-none d-md-inline' />" + dateElts[1] + "\xA0" + dateElts[2];
            var nbTimeItems = Object.keys(entry.hourProposals).length;
            itemString += "<div class='text-md-center ob1-date-time-picker-day-times'>"; // affichage de chaque jour

            if (nbTimeItems !== 0) {
              itemString += "<div class=\"date-title mx-auto\">" + entryDate + "</div>"; // affichage des boutons en fonction de la disponibilité pour sélection de l'heure

              for (var j = 0; j < nbTimeSlotsMax; j++) {
                var hour = Object.keys(entry.hourProposals)[j];
                var status = entry.hourProposals[hour];
                var statusClass = "hour-disable";

                if (status === "AVAILABLE") {
                  statusClass = "";
                } else if (status === "SELECTED") {
                  statusClass = "selected";
                }

                if (hour) {
                  itemString += "<button  \n                                  class=\"btn-hour selectDateHour " + statusClass + "\" \n                                  datadate=\"" + entry.dateProposals + "\" datahour=\"" + hour + "\"\n                                  " + (statusClass === "hour-disable" ? "disabled" : "") + ">" + hour + "</button>";
                } else {
                  itemString += "<button class=\"btn-hour selectDateHour " + statusClass + "\" disabled>-</button>";
                }
              }
            } else {
              // s'il n'y a aucun horaire pour la journée, affichage d'une info sur petits écrans
              itemString += "<div class=\"date-title disabled\">" + entryDate + "</div>";
              itemString += "<div class=\"d-md-none px-0\">\n                              <div class=\"alert-container alert-info px-2\" role=\"alert\">\n                                <p class=\"alert\">\n                                  <span class=\"alert-icon\" aria-hidden=\"true\"></span>\n                                  <span class=\"ob1-alert-title text-left\">\n                                    Aucun horaire disponible pour cette journ\xE9e\n                                  </span>\n                                </p>\n                              </div>\n                            </div>"; // et de - sur grands écrans

              for (var _j = 0; _j < nbTimeSlotsMax; _j++) {
                itemString += "<button class='btn-hour hour-disable d-none d-md-block' disabled>-</button>";
              }
            }

            itemString += "</div>";
          }
        }

        itemString += "<div class=\"ob1-date-time-picker-arrow\"></div>\n          </div>\n        </div>";
      } // affichage des boutons du swiper


      itemString += "</div>\n         <div class=\"swiper-button-prev d-none d-md-block\" title=\"Pr\xE9c\xE9dant\"></div>\n         <div class=\"swiper-button-next d-none d-md-block\" title=\"Suivant\"></div>\n      </div>\n      <!-- BOUTONS TEXTUELS SUPPLEMENTAIRES DE SWIPE : VERSION DESKTOP UNIQUEMENT -->\n      <div class=\"row my-3 d-none d-md-flex\">\n         <div class=\"col-6 text-right\"><button class=\"btn btn-secondary disabled swipeLeft\" \n             id=\"prevDayButton\">Jours pr\xE9c\xE9dents</button></div>\n         <div class=\"col-6\"><button class=\"btn btn-secondary swipeRight\" \n             id=\"nextDayButton\">Prochains jours</button></div>\n      </div>"; // Injection du contenu HTML généré

      this.container.innerHTML = itemString; // Initialisation du swiper

      this.mySwiper = new Swiper(".swiper-container", {
        autoplay: false,
        // enable accessibility
        a11y: true,
        keyboard: {
          enabled: true,
          onlyInViewport: false
        },
        freeMode: false,
        // If we need pagination
        pagination: false,
        // Navigation arrows
        navigation: {
          nextEl: ".swiper-button-next",
          prevEl: ".swiper-button-prev"
        },
        slidesPerView: 1,
        centeredSlides: true,
        on: {
          slideChange: function slideChange() {
            _this.isSwiperAtBeginning();

            _this.isSwiperAtEnd();
          }
        }
      }); // Ajout de nouvelles fonctionnalités de swipe pour les différents boutons

      this.dateTimePickerSwiper = this.container.querySelector(".swiper-container").swiper; // gestion de l'évenement resize du navigateur

      this._onResize = function () {
        _this.changeDisplayMode();
      };

      window.addEventListener("resize", this._onResize); // Appel de la méthode d'affichage du swiper ou non, au chargement

      this.changeDisplayMode(); // Gestion des écouteurs

      this._onClick = function (event) {
        if (event.target.classList.contains("swipeLeft")) {
          _this.swipeLeft();
        } else if (event.target.classList.contains("swipeRight")) {
          _this.swipeRight();
        } else if (event.target.classList.contains("selectDateHour")) {
          var selectedDate = event.target.attributes.datadate.value;
          var selectedHour = event.target.attributes.datahour.value;

          _this.setDateTimeForm(event.target, selectedDate, selectedHour);
        }
      };

      this.container.addEventListener("click", this._onClick);
    };

    _proto.swipeLeft = function swipeLeft() {
      this.dateTimePickerSwiper.slidePrev();
      this.isSwiperAtBeginning();
    };

    _proto.swipeRight = function swipeRight() {
      this.dateTimePickerSwiper.slideNext();
      this.isSwiperAtEnd();
    };

    _proto.swipeToNextAvailableDate = function swipeToNextAvailableDate(slideIndex) {
      this.dateTimePickerSwiper.slideTo(slideIndex);
    };

    _proto.isSwiperAtBeginning = function isSwiperAtBeginning() {
      var button = this.container.querySelector("#prevDayButton");

      if (this.dateTimePickerSwiper.isBeginning === true) {
        button.classList.add("disabled");
      } else {
        button.classList.remove("disabled");
      }
    };

    _proto.isSwiperAtEnd = function isSwiperAtEnd() {
      var button = this.container.querySelector("#nextDayButton");

      if (this.dateTimePickerSwiper.isEnd === true) {
        button.classList.add("disabled");
      } else {
        button.classList.remove("disabled");
      }
    } // affichage ou masquage du swiper en fonction de la résolution
    ;

    _proto.changeDisplayMode = function changeDisplayMode() {
      this.dateTimePickerSwiper = this.container.querySelector(".swiper-container").swiper;
      var swiperContent = this.container.querySelector(".swiper-content");
      var swiperItem = this.container.querySelector(".swiper-item");
      var w = document.documentElement.clientWidth;

      if (w < breakpoints.MEDIUM) {
        this.dateTimePickerSwiper.allowSlidePrev = false;
        this.dateTimePickerSwiper.allowSlideNext = false;
        swiperContent.classList.remove("swiper-wrapper", "d-flex");
        swiperItem.classList.remove("swiper-slide");
        swiperItem.style.width = "100%";
        this.dateTimePickerSwiper.slideTo(0);
      } else {
        this.dateTimePickerSwiper.allowSlidePrev = true;
        this.dateTimePickerSwiper.allowSlideNext = true;
        swiperContent.classList.add("swiper-wrapper", "d-flex");
        swiperItem.classList.add("swiper-slide");
        this.dateTimePickerSwiper.slideTo(0);
      }
    } // fonction pour passer aux champs cachés la valeur sélectionnée par l'utilisateur
    ;

    _proto.setDateTimeForm = function setDateTimeForm(elt, date, hour) {
      var selectedButton = this.container.querySelector("button.selected");

      if (selectedButton != null) {
        selectedButton.classList.remove("selected");
      }

      elt.classList.add("selected");
      var dateSelected = new Date(date).toISOString().slice(0, 10);
      var timeSelected = hour;

      if (document.getElementById("selectedDate")) {
        document.getElementById("selectedDate").value = dateSelected;
      }

      if (document.getElementById("selectedDate")) {
        document.getElementById("selectedTime").value = timeSelected;
      }
    };

    function DateTimePicker(container, proposals) {
      if (container) {
        if (typeof container.dataset.ref === "undefined") {
          this.ref = Math.random();
          DateTimePicker.refs[this.ref] = this;
          container.dataset.ref = this.ref;
          this.init(container, proposals);
        } else {
          // If this element has already been instantiated, use the existing reference.
          return DateTimePicker.refs[container.dataset.ref];
        }
      }
    }
    /**
     * Décharge le composant
     */


    _proto.dispose = function dispose() {
      window.removeEventListener("resize", this._onResize);
      this.container.removeEventListener("click", this._onClick);
    };

    return DateTimePicker;
  }();

  DateTimePicker.refs = {}; // rattachement au contexte window pour pouvoir l'utiliser en dehors du JS

  window.DateTimePicker = DateTimePicker;

  var PAGE_MENU_LISTENERS = {
    CLICK: "click"
  };
  var PAGE_MENU_CLASSES = {
    ITEM_ACTIVE: "active",
    ITEM_INLINE: "ob1-nav-inline",
    DROPDOWN: "ob1-menu-page-dropdown",
    // on utilise pas .dropdown pour éviter l'instanciation du composant
    DROPDOWN_MENU: "dropdown-menu",
    DROPDOWN_ITEM: "dropdown-item",
    MORE_ITEMS_HIDDEN: "d-none",
    NAV_LINK: "nav-link",
    NAV_ITEM: "nav-item"
  };
  var ATTRIBUTES = {
    HREF: "href",
    HREF_VALUE: "#"
  };
  var PAGE_MENU_TEXTS = {
    MORE_ITEMS_NAME: "Plus"
  }; // la liste des sélecteurs que l'on utilise dans le code du composant

  var PAGE_MENU_SELECTORS = {
    CONTAINER: ".nav.o-nav-light",
    ALL_ITEMS: ".nav.o-nav-light .nav-item",
    NAV_LINK: ".nav-link",
    DROPDOWN_LINK: ".ob1-menu-page-dropdown .nav-link",
    DROPDOWN_MENU: ".dropdown-menu",
    DROPDOWN_ITEM: ".dropdown-item"
  };

  var PageMenu = /*#__PURE__*/function () {
    /**
     * Constructeur
     * @param {HTMLElement} pageMenu - L'élément représentant le menu de navigation
     */
    function PageMenu(pageMenu) {
      var _this = this;

      this.pageMenu = pageMenu; // Si le PageMenu a déjà été instancié sur ce noeud on ne réinstancie pas

      if (this.pageMenu.dataset.refPageMenu === "true") {
        return;
      } // On initialise l'élément "Plus" qui contiendra les items ne contenant pas sur une seule ligne


      this.moreItems = this.createMoreItemsElement(); // Liste des items présents dans l'élément "Plus"

      this.moreItemsList = this.moreItems.querySelector(PAGE_MENU_SELECTORS.DROPDOWN_MENU); // Lien du dropdown - "Plus"

      this.moreItemsLink = this.pageMenu.querySelector(PAGE_MENU_SELECTORS.DROPDOWN_LINK); // Si aucun élément n'est sélectionné, on sélectionne par défaut le premier élément

      var items = pageMenu.querySelectorAll(PAGE_MENU_SELECTORS.ALL_ITEMS);
      var isOneSelected = false;

      for (var _iterator = _createForOfIteratorHelperLoose(items), _step; !(_step = _iterator()).done;) {
        var item = _step.value;

        if (item.classList.contains(PAGE_MENU_CLASSES.ITEM_ACTIVE)) {
          isOneSelected = true;
          break;
        }
      }

      if (!isOneSelected) {
        pageMenu.querySelector(PAGE_MENU_SELECTORS.ALL_ITEMS).classList.add(PAGE_MENU_CLASSES.ITEM_ACTIVE);
      } // On met en place des listners permettant la mise en évidence (soulignement + couleur Orange) de l'item sélectionné


      this.setActiveItemManagement(); // Si on est sur un device n'utilisant pas de souris

      if (window.matchMedia("(hover:none)").matches) {
        // On affiche les items sur une seule ligne afin que l'utilisateur puisse swipper
        document.querySelector(PAGE_MENU_SELECTORS.CONTAINER).classList.add(PAGE_MENU_CLASSES.ITEM_INLINE);
        this.showOrHideMoreItems();
      } else {
        // On appelle la méthode de redimmensionnement du menu afin d'ajouter/retirer d'éventuels items dans l'élément "Plus"
        this.resize(); // On crée un listener pour gérer l'ajout/retrait d'items dans l'élément "Plus" lors d'un redimensionnement de la page

        window.addEventListener("resize", function () {
          _this.resize();
        });
      }

      this.pageMenu.dataset.refPageMenu = "true";
    }
    /**
     * Permet de gérer le redimensionnement du composant
     */


    var _proto = PageMenu.prototype;

    _proto.resize = function resize() {
      // On ajoute la classe "d-block" afin de pouvoir accéder aux tailles des items présents dans l'élément "Plus" (on la supprimera à la fin des calculs)
      this.showOrHideMoreItemsList(true); // Largeur du composant et du dropdown de l'élément "Plus"

      var containerWidth = this.pageMenu.offsetWidth;
      var moreItemsListWidth = this.moreItemsList.offsetWidth; // Nombre d'items hors du dropdown et dans le dropdown

      var numberChildren = this.pageMenu.children.length - 1;
      var numberMoreItemsListChildren = this.moreItemsList.childElementCount; // La marge de sécurité est déterminée à partir de la taille du + grand item du menu afin qu'aucun item ne soit affiché sur une 2ème ligne

      var securityMargin = this.getSecurityMargin(); // Initilisation de variables

      var childrenWidth = 0;
      var indexChildToMove = 0;
      var indexMoreItemsListChildToMove = 0;
      var moveChildrenIn = false;
      var moveChildrenOut = false; // On cherche l'index de l'enfant à partir duquel on va effectuer la bascule dans la liste "Plus"

      for (var indexChild = 0; indexChild < numberChildren; indexChild++) {
        childrenWidth += this.pageMenu.children[indexChild].offsetWidth;

        if (!moveChildrenIn && childrenWidth + securityMargin > containerWidth) {
          indexChildToMove = indexChild;
          moveChildrenIn = true;
        }
      } // Au contraire, on vérifie si on peut sortir des items de la liste "Plus"


      if (numberMoreItemsListChildren > 0) {
        for (var indexMoreItemsListChild = 0; indexMoreItemsListChild < numberMoreItemsListChildren; indexMoreItemsListChild++) {
          if (!moveChildrenIn && containerWidth > childrenWidth + moreItemsListWidth + securityMargin) {
            indexMoreItemsListChildToMove = indexMoreItemsListChild;
            moveChildrenOut = true;
          }
        }
      } // On fait la bascule en fonction des cas identifiés précédemment


      if (moveChildrenIn) {
        for (var _indexChild = numberChildren; _indexChild >= 0; _indexChild--) {
          // On déplace les éléments dans la liste "Plus"
          if (indexChildToMove > 0 && _indexChild >= indexChildToMove && this.pageMenu.children[_indexChild] !== this.moreItems) {
            var elementToMove = this.pageMenu.children[_indexChild];
            var elementToAdd = elementToMove.querySelector(".nav-link");
            elementToAdd.classList.add(PAGE_MENU_CLASSES.DROPDOWN_ITEM);
            elementToAdd.classList.remove("nav-link"); // Si au moins 1 item est déjà présent dans "Plus" , on insère le nouvel item au début de la liste

            if (this.moreItemsList.childElementCount > 0) {
              this.moreItemsList.insertBefore(elementToAdd, this.moreItemsList.querySelector(PAGE_MENU_SELECTORS.DROPDOWN_ITEM)); // Sinon on ajoute l'item dans la liste vide
            } else {
              this.moreItemsList.appendChild(elementToAdd);
            } // On change les styles de l'élément déplacé et de l'item "Plus"


            if (elementToMove.classList.contains(PAGE_MENU_CLASSES.ITEM_ACTIVE)) {
              this.moreItems.classList.add(PAGE_MENU_CLASSES.ITEM_ACTIVE);
              elementToAdd.classList.add(PAGE_MENU_CLASSES.ITEM_ACTIVE);
              this.moreItemsLink.textContent = elementToAdd.textContent;
            }

            this.pageMenu.removeChild(elementToMove);
          }
        }
      } else if (moveChildrenOut) {
        // On sort le 1er élément de la liste d'items présents dans l'élément "Plus" pour le placer entre le dernier item en dehors et l'élément "Plus"
        var index = 0;

        while (index <= indexMoreItemsListChildToMove) {
          var _elementToMove = this.moreItemsList.querySelector(PAGE_MENU_SELECTORS.DROPDOWN_ITEM);

          var _elementToAdd = document.createElement("li");

          _elementToAdd.classList.add(PAGE_MENU_CLASSES.NAV_ITEM);

          _elementToMove.classList.add(PAGE_MENU_CLASSES.NAV_LINK);

          _elementToMove.classList.remove(PAGE_MENU_CLASSES.DROPDOWN_ITEM);

          _elementToAdd.appendChild(_elementToMove);

          if (_elementToMove.classList.contains(PAGE_MENU_CLASSES.ITEM_ACTIVE)) {
            this.moreItems.classList.remove(PAGE_MENU_CLASSES.ITEM_ACTIVE);

            _elementToAdd.classList.add(PAGE_MENU_CLASSES.ITEM_ACTIVE);

            this.moreItemsLink.textContent = PAGE_MENU_TEXTS.MORE_ITEMS_NAME;
          }

          this.pageMenu.insertBefore(_elementToAdd, this.pageMenu.children[this.pageMenu.childElementCount - 1]);
          index++;
        }
      } // On masque la liste des items présents dans l'élément "Plus" pour qu'ils ne soient visibles qu'au suvol de ce dernier


      this.showOrHideMoreItemsList(false); // On masque l'élément "Plus" s'il est vide

      this.showOrHideMoreItems();
    }
    /**
     * Permet de connaître la marge de sécurité à prendre en compte lors d'un ajout/suppresion d'item dans la liste "Plus"
     * @return {number} - La marge de sécurité
     */
    ;

    _proto.getSecurityMargin = function getSecurityMargin() {
      var securityMargin = 0;

      for (var item in this.pageMenu.children) {
        if (this.pageMenu.children[item].offsetWidth > securityMargin) {
          securityMargin = this.pageMenu.children[item].offsetWidth;
        }
      }

      return securityMargin;
    }
    /**
     * Crée l'élément appelé "Plus" et contenant les items du menu ne pouvant pas être affichés sur une seule ligne
     * @return {HTMLElement} - L'élément "Plus"
     */
    ;

    _proto.createMoreItemsElement = function createMoreItemsElement() {
      var moreItemsElement = document.createElement("li");
      moreItemsElement.classList.add(PAGE_MENU_CLASSES.DROPDOWN);
      moreItemsElement.classList.add(PAGE_MENU_CLASSES.NAV_ITEM);
      var linkMoreItemsElement = document.createElement("a");
      linkMoreItemsElement.setAttribute(ATTRIBUTES.HREF, ATTRIBUTES.HREF_VALUE);
      linkMoreItemsElement.classList.add(PAGE_MENU_CLASSES.NAV_LINK);
      linkMoreItemsElement.classList.add("o-link-arrow");
      linkMoreItemsElement.classList.add("down");
      linkMoreItemsElement.innerText = PAGE_MENU_TEXTS.MORE_ITEMS_NAME;
      var moreItemsList = document.createElement("div");
      moreItemsList.classList.add(PAGE_MENU_CLASSES.DROPDOWN_MENU);
      moreItemsElement.appendChild(linkMoreItemsElement);
      moreItemsElement.appendChild(moreItemsList);
      this.pageMenu.appendChild(moreItemsElement);
      return moreItemsElement;
    }
    /**
     * Affiche/masque l'élément "Plus" en fonction du nombre d'items présents dans cet élément
     */
    ;

    _proto.showOrHideMoreItems = function showOrHideMoreItems() {
      if (this.moreItemsList.childElementCount === 0) {
        this.moreItems.classList.add(PAGE_MENU_CLASSES.MORE_ITEMS_HIDDEN);
      } else if (this.moreItemsList.childElementCount > 0) {
        this.moreItems.classList.remove(PAGE_MENU_CLASSES.MORE_ITEMS_HIDDEN);
      }
    }
    /**
     * Affiche/masque la liste des items présents dans "Plus"
     * @param {boolean} show - Affiche/Masque la liste des items présents dans l'élément "Plus"
     */
    ;

    _proto.showOrHideMoreItemsList = function showOrHideMoreItemsList(show) {
      if (show) {
        this.moreItems.classList.remove("d-none");
        this.moreItemsList.classList.add("show");
        this.moreItemsList.classList.add("invisible");
      } else {
        this.moreItems.classList.add("d-none");
        this.moreItemsList.classList.remove("show");
        this.moreItemsList.classList.remove("invisible");
      }
    }
    /**
     * Création de listeners permettant la mise en valeur d'un item lors d'un clic sur ce dernier
     */
    ;

    _proto.setActiveItemManagement = function setActiveItemManagement() {
      var _this2 = this;

      // Listener appelé au clic sur un élément non compris dans le dropdown
      this._onElClick = function (event) {
        _this2.removeAllActiveClasses();

        if (event.target.classList.contains("dropdown-item")) {
          event.target.classList.add(PAGE_MENU_CLASSES.ITEM_ACTIVE);

          _this2.moreItems.classList.add(PAGE_MENU_CLASSES.ITEM_ACTIVE); // On met à jour le label de l'élément "Plus"


          _this2.moreItemsLink.innerText = event.target.innerText;
        } else {
          event.target.parentElement.classList.add(PAGE_MENU_CLASSES.ITEM_ACTIVE);
          _this2.moreItemsLink.innerText = PAGE_MENU_TEXTS.MORE_ITEMS_NAME;
        }

        event.preventDefault();
      };

      this._callbackForEachLink(function (link) {
        return link.addEventListener(PAGE_MENU_LISTENERS.CLICK, _this2._onElClick);
      }); // On ajoute un listener sur l'élément "Plus"


      this._onMoreClick = function (event) {
        return event.preventDefault();
      };

      this.moreItemsLink.addEventListener(PAGE_MENU_LISTENERS.CLICK, this._onMoreClick);
    }
    /**
     * Supprime la classe "active" de tous les éléments, dropdown ou non
     */
    ;

    _proto.removeAllActiveClasses = function removeAllActiveClasses() {
      Array.prototype.slice.call(this.pageMenu.children, 0).concat(Array.prototype.slice.call(this.moreItemsList.children, 0)).forEach(function (child) {
        return child.classList.remove(PAGE_MENU_CLASSES.ITEM_ACTIVE);
      });
    }
    /**
     * Décharge le composant
     */
    ;

    _proto.dispose = function dispose() {
      var _this3 = this;

      window.removeEventListener("resize", this.resize);

      this._callbackForEachLink(function (elem) {
        return elem.removeEventListener(PAGE_MENU_LISTENERS.CLICK, _this3._onElClick);
      });

      this.moreItemsLink.removeEventListener(PAGE_MENU_LISTENERS.CLICK, this._onMoreClick);
    }
    /**
     * Appelle la callback pour chaque lien du Page Menu (sauf lien Plus) avec le HTMLElement du lien en paramètre
     */
    ;

    _proto._callbackForEachLink = function _callbackForEachLink(callbackfn) {
      Array.prototype.slice.call(this.pageMenu.children, 0).filter(function (listItem) {
        return !listItem.classList.contains("dropdown");
      }).map(function (element) {
        return element.querySelector(".nav-link");
      }).filter(function (item) {
        return item;
      }) // querySelector pourrait retourner null si le dom n'est pas correct
      .concat(Array.prototype.slice.call(this.moreItemsList.children, 0)).forEach(callbackfn);
    };

    return PageMenu;
  }();

  document.addEventListener("DOMContentLoaded", function () {
    var pageMenus = document.querySelectorAll(PAGE_MENU_SELECTORS.CONTAINER);
    [].forEach.call(pageMenus, function (pageMenu) {
      new PageMenu(pageMenu);
    });
  }); // rattachement au contexte window pour pouvoir l'utiliser en dehors du JS

  window.PageMenu = PageMenu;

  var dropdown = createCommonjsModule(function (module, exports) {
  /*!
    * Boosted v4.3.1 (https://boosted.orange.com)
    * Copyright 2014-2019 The Boosted Authors
    * Copyright 2014-2019 Orange
    * Licensed under MIT (https://github.com/orange-opensource/orange-boosted-bootstrap/blob/master/LICENSE)
    * This a fork of Bootstrap : Initial license below
    * Bootstrap dropdown.js v4.3.1 (https://boosted.orange.com)
    * Copyright 2011-2019 The Boosted Authors (https://github.com/Orange-OpenSource/Orange-Boosted-Bootstrap/graphs/contributors)
    * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
    */
  (function (global, factory) {
     module.exports = factory(jquery, popper, util) ;
  }(commonjsGlobal, function ($, Popper, Util) {
    $ = $ && $.hasOwnProperty('default') ? $['default'] : $;
    Popper = Popper && Popper.hasOwnProperty('default') ? Popper['default'] : Popper;
    Util = Util && Util.hasOwnProperty('default') ? Util['default'] : Util;

    function _defineProperties(target, props) {
      for (var i = 0; i < props.length; i++) {
        var descriptor = props[i];
        descriptor.enumerable = descriptor.enumerable || false;
        descriptor.configurable = true;
        if ("value" in descriptor) descriptor.writable = true;
        Object.defineProperty(target, descriptor.key, descriptor);
      }
    }

    function _createClass(Constructor, protoProps, staticProps) {
      if (protoProps) _defineProperties(Constructor.prototype, protoProps);
      if (staticProps) _defineProperties(Constructor, staticProps);
      return Constructor;
    }

    function _defineProperty(obj, key, value) {
      if (key in obj) {
        Object.defineProperty(obj, key, {
          value: value,
          enumerable: true,
          configurable: true,
          writable: true
        });
      } else {
        obj[key] = value;
      }

      return obj;
    }

    function _objectSpread(target) {
      for (var i = 1; i < arguments.length; i++) {
        var source = arguments[i] != null ? arguments[i] : {};
        var ownKeys = Object.keys(source);

        if (typeof Object.getOwnPropertySymbols === 'function') {
          ownKeys = ownKeys.concat(Object.getOwnPropertySymbols(source).filter(function (sym) {
            return Object.getOwnPropertyDescriptor(source, sym).enumerable;
          }));
        }

        ownKeys.forEach(function (key) {
          _defineProperty(target, key, source[key]);
        });
      }

      return target;
    }

    /**
     * ------------------------------------------------------------------------
     * Constants
     * ------------------------------------------------------------------------
     */

    var NAME = 'dropdown';
    var VERSION = '4.3.1';
    var DATA_KEY = 'bs.dropdown';
    var EVENT_KEY = "." + DATA_KEY;
    var DATA_API_KEY = '.data-api';
    var JQUERY_NO_CONFLICT = $.fn[NAME];
    var ESCAPE_KEYCODE = 27; // KeyboardEvent.which value for Escape (Esc) key

    var SPACE_KEYCODE = 32; // KeyboardEvent.which value for space key

    var TAB_KEYCODE = 9; // KeyboardEvent.which value for tab key

    var ARROW_UP_KEYCODE = 38; // KeyboardEvent.which value for up arrow key

    var ARROW_DOWN_KEYCODE = 40; // KeyboardEvent.which value for down arrow key

    var RIGHT_MOUSE_BUTTON_WHICH = 3; // MouseEvent.which value for the right button (assuming a right-handed mouse)

    var REGEXP_KEYDOWN = new RegExp(ARROW_UP_KEYCODE + "|" + ARROW_DOWN_KEYCODE + "|" + ESCAPE_KEYCODE);
    var Event = {
      HIDE: "hide" + EVENT_KEY,
      HIDDEN: "hidden" + EVENT_KEY,
      SHOW: "show" + EVENT_KEY,
      SHOWN: "shown" + EVENT_KEY,
      CLICK: "click" + EVENT_KEY,
      CLICK_DATA_API: "click" + EVENT_KEY + DATA_API_KEY,
      KEYDOWN_DATA_API: "keydown" + EVENT_KEY + DATA_API_KEY,
      KEYUP_DATA_API: "keyup" + EVENT_KEY + DATA_API_KEY
    };
    var ClassName = {
      DISABLED: 'disabled',
      SHOW: 'show',
      DROPUP: 'dropup',
      DROPRIGHT: 'dropright',
      DROPLEFT: 'dropleft',
      MENURIGHT: 'dropdown-menu-right',
      MENULEFT: 'dropdown-menu-left',
      POSITION_STATIC: 'position-static'
    };
    var Selector = {
      DATA_TOGGLE: '[data-toggle="dropdown"]',
      FORM_CHILD: '.dropdown form',
      MENU: '.dropdown-menu',
      NAVBAR_NAV: '.navbar-nav',
      // Boosted mod
      MENU_ITEMS: '.dropdown-menu .dropdown-item',
      FIRST_ITEM_IN_MENU: '.dropdown-menu .dropdown-item:not(.disabled), .dropdown-menu .nav-link:not(.disabled)',
      // end mod
      VISIBLE_ITEMS: '.dropdown-menu .dropdown-item:not(.disabled):not(:disabled)'
    };
    var AttachmentMap = {
      TOP: 'top-start',
      TOPEND: 'top-end',
      BOTTOM: 'bottom-start',
      BOTTOMEND: 'bottom-end',
      RIGHT: 'right-start',
      RIGHTEND: 'right-end',
      LEFT: 'left-start',
      LEFTEND: 'left-end'
    };
    var Default = {
      offset: 0,
      flip: true,
      boundary: 'scrollParent',
      reference: 'toggle',
      display: 'dynamic'
    };
    var DefaultType = {
      offset: '(number|string|function)',
      flip: 'boolean',
      boundary: '(string|element)',
      reference: '(string|element)',
      display: 'string'
      /**
       * ------------------------------------------------------------------------
       * Class Definition
       * ------------------------------------------------------------------------
       */

    };

    var Dropdown =
    /*#__PURE__*/
    function () {
      function Dropdown(element, config) {
        this._element = element;
        this._popper = null;
        this._config = this._getConfig(config);
        this._menu = this._getMenuElement();
        this._inNavbar = this._detectNavbar();

        this._addEventListeners();

        this._addAccessibility(); // Boosted mod

      } // Getters


      var _proto = Dropdown.prototype;

      // Public
      _proto.toggle = function toggle() {
        if (this._element.disabled || $(this._element).hasClass(ClassName.DISABLED)) {
          return;
        }

        var parent = Dropdown._getParentFromElement(this._element);

        var isActive = $(this._menu).hasClass(ClassName.SHOW);

        Dropdown._clearMenus();

        if (isActive) {
          return;
        }

        var relatedTarget = {
          relatedTarget: this._element
        };
        var showEvent = $.Event(Event.SHOW, relatedTarget);
        $(parent).trigger(showEvent);

        if (showEvent.isDefaultPrevented()) {
          return;
        } // Disable totally Popper.js for Dropdown in Navbar


        if (!this._inNavbar) {
          /**
           * Check for Popper dependency
           * Popper - https://popper.js.org
           */
          if (typeof Popper === 'undefined') {
            throw new TypeError('Bootstrap\'s dropdowns require Popper.js (https://popper.js.org/)');
          }

          var referenceElement = this._element;

          if (this._config.reference === 'parent') {
            referenceElement = parent;
          } else if (Util.isElement(this._config.reference)) {
            referenceElement = this._config.reference; // Check if it's jQuery element

            if (typeof this._config.reference.jquery !== 'undefined') {
              referenceElement = this._config.reference[0];
            }
          } // If boundary is not `scrollParent`, then set position to `static`
          // to allow the menu to "escape" the scroll parent's boundaries
          // https://github.com/twbs/bootstrap/issues/24251


          if (this._config.boundary !== 'scrollParent') {
            $(parent).addClass(ClassName.POSITION_STATIC);
          }

          this._popper = new Popper(referenceElement, this._menu, this._getPopperConfig());
        } // If this is a touch-enabled device we add extra
        // empty mouseover listeners to the body's immediate children;
        // only needed because of broken event delegation on iOS
        // https://www.quirksmode.org/blog/archives/2014/02/mouse_event_bub.html


        if ('ontouchstart' in document.documentElement && $(parent).closest(Selector.NAVBAR_NAV).length === 0) {
          $(document.body).children().on('mouseover', null, $.noop);
        }

        this._element.focus();

        this._element.setAttribute('aria-expanded', true);

        $(this._menu).toggleClass(ClassName.SHOW);
        $(parent).toggleClass(ClassName.SHOW).trigger($.Event(Event.SHOWN, relatedTarget));
      };

      _proto.show = function show() {
        if (this._element.disabled || $(this._element).hasClass(ClassName.DISABLED) || $(this._menu).hasClass(ClassName.SHOW)) {
          return;
        }

        var relatedTarget = {
          relatedTarget: this._element
        };
        var showEvent = $.Event(Event.SHOW, relatedTarget);

        var parent = Dropdown._getParentFromElement(this._element);

        $(parent).trigger(showEvent);

        if (showEvent.isDefaultPrevented()) {
          return;
        }

        $(this._menu).toggleClass(ClassName.SHOW);
        $(parent).toggleClass(ClassName.SHOW).trigger($.Event(Event.SHOWN, relatedTarget)); // Boosted mod

        $(parent).find(Selector.FIRST_ITEM_IN_MENU).first().trigger('focus'); // end mod
      };

      _proto.hide = function hide() {
        if (this._element.disabled || $(this._element).hasClass(ClassName.DISABLED) || !$(this._menu).hasClass(ClassName.SHOW)) {
          return;
        }

        var relatedTarget = {
          relatedTarget: this._element
        };
        var hideEvent = $.Event(Event.HIDE, relatedTarget);

        var parent = Dropdown._getParentFromElement(this._element);

        $(parent).trigger(hideEvent);

        if (hideEvent.isDefaultPrevented()) {
          return;
        }

        $(this._menu).toggleClass(ClassName.SHOW);
        $(parent).toggleClass(ClassName.SHOW).trigger($.Event(Event.HIDDEN, relatedTarget));
      };

      _proto.dispose = function dispose() {
        $.removeData(this._element, DATA_KEY);
        $(this._element).off(EVENT_KEY);
        this._element = null;
        this._menu = null;

        if (this._popper !== null) {
          this._popper.destroy();

          this._popper = null;
        }
      };

      _proto.update = function update() {
        this._inNavbar = this._detectNavbar();

        if (this._popper !== null) {
          this._popper.scheduleUpdate();
        }
      } // Private
      ;

      _proto._addEventListeners = function _addEventListeners() {
        var _this = this;

        $(this._element).on(Event.CLICK, function (event) {
          event.preventDefault();
          event.stopPropagation();

          _this.toggle();
        });
      };

      _proto._getConfig = function _getConfig(config) {
        config = _objectSpread({}, this.constructor.Default, $(this._element).data(), config);
        Util.typeCheckConfig(NAME, config, this.constructor.DefaultType);
        return config;
      };

      _proto._getMenuElement = function _getMenuElement() {
        if (!this._menu) {
          var parent = Dropdown._getParentFromElement(this._element);

          if (parent) {
            this._menu = parent.querySelector(Selector.MENU);
          }
        }

        return this._menu;
      };

      _proto._getPlacement = function _getPlacement() {
        var $parentDropdown = $(this._element.parentNode);
        var placement = AttachmentMap.BOTTOM; // Handle dropup

        if ($parentDropdown.hasClass(ClassName.DROPUP)) {
          placement = AttachmentMap.TOP;

          if ($(this._menu).hasClass(ClassName.MENURIGHT)) {
            placement = AttachmentMap.TOPEND;
          }
        } else if ($parentDropdown.hasClass(ClassName.DROPRIGHT)) {
          placement = AttachmentMap.RIGHT;
        } else if ($parentDropdown.hasClass(ClassName.DROPLEFT)) {
          placement = AttachmentMap.LEFT;
        } else if ($(this._menu).hasClass(ClassName.MENURIGHT)) {
          placement = AttachmentMap.BOTTOMEND;
        }

        return placement;
      };

      _proto._detectNavbar = function _detectNavbar() {
        return $(this._element).closest('.navbar').length > 0;
      };

      _proto._getOffset = function _getOffset() {
        var _this2 = this;

        var offset = {};

        if (typeof this._config.offset === 'function') {
          offset.fn = function (data) {
            data.offsets = _objectSpread({}, data.offsets, _this2._config.offset(data.offsets, _this2._element) || {});
            return data;
          };
        } else {
          offset.offset = this._config.offset;
        }

        return offset;
      };

      _proto._getPopperConfig = function _getPopperConfig() {
        var popperConfig = {
          placement: this._getPlacement(),
          modifiers: {
            offset: this._getOffset(),
            flip: {
              enabled: this._config.flip
            },
            preventOverflow: {
              boundariesElement: this._config.boundary
            }
          } // Disable Popper.js if we have a static display

        };

        if (this._config.display === 'static') {
          popperConfig.modifiers.applyStyle = {
            enabled: false
          };
        }

        return popperConfig;
      } // Boosted mod
      ;

      _proto._addAccessibility = function _addAccessibility() {
        $(this._element).attr('aria-haspopup', true); // ensure that dropdown-menu have the role menu

        $(this._element).parent().children(Selector.MENU).attr('role', 'menu'); // ensure that dropdown-itm's have the role menuitem

        $(this._element).parent().children(Selector.MENU).children('.dropdown-item').attr('role', 'menuitem');
      } // end mod
      // Static
      ;

      Dropdown._jQueryInterface = function _jQueryInterface(config) {
        return this.each(function () {
          var data = $(this).data(DATA_KEY);

          var _config = typeof config === 'object' ? config : null;

          if (!data) {
            data = new Dropdown(this, _config);
            $(this).data(DATA_KEY, data);
          } // Boosted mod


          if (/init/.test(config)) {
            return;
          } // end mod


          if (typeof config === 'string') {
            if (typeof data[config] === 'undefined') {
              throw new TypeError("No method named \"" + config + "\"");
            }

            data[config]();
          }
        });
      };

      Dropdown._clearMenus = function _clearMenus(event) {
        if (event && (event.which === RIGHT_MOUSE_BUTTON_WHICH || event.type === 'keyup' && event.which !== TAB_KEYCODE)) {
          return;
        }

        var toggles = [].slice.call(document.querySelectorAll(Selector.DATA_TOGGLE));

        for (var i = 0, len = toggles.length; i < len; i++) {
          var parent = Dropdown._getParentFromElement(toggles[i]);

          var context = $(toggles[i]).data(DATA_KEY);
          var relatedTarget = {
            relatedTarget: toggles[i]
          };

          if (event && event.type === 'click') {
            relatedTarget.clickEvent = event;
          }

          if (!context) {
            continue;
          }

          var dropdownMenu = context._menu;

          if (!$(parent).hasClass(ClassName.SHOW)) {
            continue;
          }

          if (event && (event.type === 'click' && /input|textarea/i.test(event.target.tagName) || event.type === 'keyup' && event.which === TAB_KEYCODE) && $.contains(parent, event.target)) {
            continue;
          }

          var hideEvent = $.Event(Event.HIDE, relatedTarget);
          $(parent).trigger(hideEvent);

          if (hideEvent.isDefaultPrevented()) {
            continue;
          } // If this is a touch-enabled device we remove the extra
          // empty mouseover listeners we added for iOS support


          if ('ontouchstart' in document.documentElement) {
            $(document.body).children().off('mouseover', null, $.noop);
          }

          toggles[i].setAttribute('aria-expanded', 'false');
          $(dropdownMenu).removeClass(ClassName.SHOW);
          $(parent).removeClass(ClassName.SHOW).trigger($.Event(Event.HIDDEN, relatedTarget));
        }
      };

      Dropdown._getParentFromElement = function _getParentFromElement(element) {
        var parent;
        var selector = Util.getSelectorFromElement(element);

        if (selector) {
          parent = document.querySelector(selector);
        }

        return parent || element.parentNode;
      } // eslint-disable-next-line complexity
      ;

      Dropdown._dataApiKeydownHandler = function _dataApiKeydownHandler(event) {
        // If not input/textarea:
        //  - And not a key in REGEXP_KEYDOWN => not a dropdown command
        // If input/textarea:
        //  - If space key => not a dropdown command
        //  - If key is other than escape
        //    - If key is not up or down => not a dropdown command
        //    - If trigger inside the menu => not a dropdown command
        if (/input|textarea/i.test(event.target.tagName) ? event.which === SPACE_KEYCODE || event.which !== ESCAPE_KEYCODE && (event.which !== ARROW_DOWN_KEYCODE && event.which !== ARROW_UP_KEYCODE || $(event.target).closest(Selector.MENU).length) : !REGEXP_KEYDOWN.test(event.which)) {
          return;
        }

        event.preventDefault();
        event.stopPropagation();

        if (this.disabled || $(this).hasClass(ClassName.DISABLED)) {
          return;
        }

        var parent = Dropdown._getParentFromElement(this);

        var isActive = $(parent).hasClass(ClassName.SHOW);

        if (!isActive || isActive && (event.which === ESCAPE_KEYCODE || event.which === SPACE_KEYCODE)) {
          if (event.which === ESCAPE_KEYCODE) {
            var toggle = parent.querySelector(Selector.DATA_TOGGLE);
            $(toggle).trigger('focus');
          }

          $(this).trigger('click');
          return;
        }

        var items = [].slice.call(parent.querySelectorAll(Selector.VISIBLE_ITEMS));

        if (items.length === 0) {
          return;
        }

        var index = items.indexOf(event.target);

        if (event.which === ARROW_UP_KEYCODE && index > 0) {
          // Up
          index--;
        }

        if (event.which === ARROW_DOWN_KEYCODE && index < items.length - 1) {
          // Down
          index++;
        }

        if (index < 0) {
          index = 0;
        }

        items[index].focus();
      };

      _createClass(Dropdown, null, [{
        key: "VERSION",
        get: function get() {
          return VERSION;
        }
      }, {
        key: "Default",
        get: function get() {
          return Default;
        }
      }, {
        key: "DefaultType",
        get: function get() {
          return DefaultType;
        }
      }]);

      return Dropdown;
    }();
    /**
     * ------------------------------------------------------------------------
     * Data Api implementation
     * ------------------------------------------------------------------------
     */


    $(document).on(Event.KEYDOWN_DATA_API, Selector.DATA_TOGGLE, Dropdown._dataApiKeydownHandler).on(Event.KEYDOWN_DATA_API, Selector.MENU, Dropdown._dataApiKeydownHandler).on(Event.CLICK_DATA_API + " " + Event.KEYUP_DATA_API, Dropdown._clearMenus).on(Event.CLICK_DATA_API, Selector.DATA_TOGGLE, function (event) {
      event.preventDefault();
      event.stopPropagation();

      Dropdown._jQueryInterface.call($(this), 'toggle');
    }).on(Event.CLICK_DATA_API, Selector.FORM_CHILD, function (e) {
      e.stopPropagation();
    }) // Boosted mod
    .on('DOMContentLoaded', function () {
      // Instanciate every dropdown in the DOM
      Dropdown._jQueryInterface.call($(Selector.DATA_TOGGLE), 'init');
    }); // end mod

    /**
     * ------------------------------------------------------------------------
     * jQuery
     * ------------------------------------------------------------------------
     */

    $.fn[NAME] = Dropdown._jQueryInterface;
    $.fn[NAME].Constructor = Dropdown;

    $.fn[NAME].noConflict = function () {
      $.fn[NAME] = JQUERY_NO_CONFLICT;
      return Dropdown._jQueryInterface;
    };

    return Dropdown;

  }));

  });

  var classes$1 = {
    active: "active"
  };
  var selectors = {
    dropdown_header: "h4.dropdown-header",
    link_item: ".dropdown-item:not(div)",
    div_item: "div.dropdown-item",
    control_input: ".custom-control-input"
  };
  var events = {
    click: "click"
  };

  var DropdownComponent = /*#__PURE__*/function (_Dropdown) {
    _inheritsLoose(DropdownComponent, _Dropdown);

    function DropdownComponent(element) {
      var _this;

      _this = _Dropdown.call(this, element) || this; // On ajoute le nombre d'éléments sélectionnés dans le cas choix multiple et sous-rubrique

      if (_this._element.querySelector(selectors.dropdown_header) && _this._element.querySelector(selectors.div_item)) {
        _this._setCounts();
      }

      return _this;
    }

    var _proto = DropdownComponent.prototype;

    _proto._addEventListeners = function _addEventListeners() {
      var _this2 = this;

      // Sur les items lien du dropdown
      var linkItems = this._element.querySelectorAll(selectors.link_item);

      this._onLinkClick = function (index, event) {
        for (var childIndex = 0; childIndex < linkItems.length; childIndex++) {
          linkItems[childIndex].classList.remove(classes$1.active);
        }

        linkItems[index].classList.add(classes$1.active);
        event.preventDefault();
      };

      this._onLinkClicks = [];

      for (var index = 0; index < linkItems.length; index++) {
        this._onLinkClicks[index] = this._onLinkClick.bind(null, index);
        linkItems[index].addEventListener(events.click, this._onLinkClicks[index]);
      } // Sur les items checkbox du dropdown


      var divItems = this._element.querySelectorAll(selectors.div_item);

      this._onCheckboxClick = function (event) {
        // Si sous-rubriques, mise à jour de l'indicateur de filtres sélectionnés
        if (_this2._element.querySelector(selectors.dropdown_header) && event.target.nodeName === "INPUT") {
          var el = event.target.parentElement.parentElement;

          while (!el.matches(selectors.dropdown_header)) {
            el = el.previousElementSibling;
          }

          var count = _this2._countSelectedItemsUntilTitle(el);

          _this2._setCount(el, count);
        } // Empêche la fermeture du menu


        event.stopPropagation();
      };

      for (var _index = 0; _index < divItems.length; _index++) {
        divItems[_index].addEventListener(events.click, this._onCheckboxClick);
      }
    }
    /**
     * Ajoute le nombre d'éléments sélectionnés dans chaque section dans le cas d'un dropdown avec choix multiple et sous-rubrique
     */
    ;

    _proto._setCounts = function _setCounts() {
      var titles = this._element.querySelectorAll(selectors.dropdown_header);

      for (var index = 0; index < titles.length; index++) {
        var count = this._countSelectedItemsUntilTitle(titles[index]);

        this._setCount(titles[index], count);
      }
    }
    /**
     * Retourne le nombre d'item sélectionnés contenu dans la catégorie d'un item donné
     *
     * @param {HTMLElement} item
     * @return {number}
     */
    ;

    _proto._countSelectedItemsUntilTitle = function _countSelectedItemsUntilTitle(item) {
      // matches() polyfill
      if (!Element.prototype.matches) {
        Element.prototype.matches = Element.prototype.msMatchesSelector || Element.prototype.webkitMatchesSelector;
      }

      var siblings = [];
      item = item.nextElementSibling;

      while (item) {
        if (item.matches(selectors.dropdown_header)) {
          break;
        }

        if (!item.querySelector(selectors.control_input).matches(":checked")) {
          item = item.nextElementSibling;
          continue;
        }

        siblings.push(item);
        item = item.nextElementSibling;
      }

      return siblings.length;
    }
    /**
     * Ajoute à un titre de sous-rubrique donné le nombre d'éléments sélectionnés donné entre parenthèses
     *
     * @param {HTMLElement} title
     * @param {number} count
     */
    ;

    _proto._setCount = function _setCount(title, count) {
      if (/.*\([0-9]+\)$/.test(title.innerText)) {
        if (count === 0) {
          title.innerText = title.innerText.replace(/\([0-9]+\)$/, "");
        } else {
          title.innerText = title.innerText.replace(/\([0-9]+\)$/, "(" + count + ")");
        }
      } else {
        if (count === 0) {
          return;
        } else {
          title.innerText += " (" + count + ")";
        }
      }
    }
    /**
     * Décharge le composant
     */
    ;

    _proto.dispose = function dispose() {
      // suppression de tous les event listeners qui ont été créés
      var linkItems = this._element.querySelectorAll(selectors.link_item);

      for (var index = 0; index < linkItems.length; index++) {
        linkItems[index].removeEventListener(events.click, this._onLinkClicks[index]);
      }

      var divItems = this._element.querySelectorAll(selectors.div_item);

      for (var _index2 = 0; _index2 < divItems.length; _index2++) {
        divItems[_index2].removeEventListener(events.click, this._onCheckboxClick);
      } // on appelle la méthode de suppression de composant d'Ob1Component (obligatoire)


      _Dropdown.prototype.dispose.call(this);
    };

    return DropdownComponent;
  }(dropdown);

  document.addEventListener("DOMContentLoaded", function () {
    Array.from(document.querySelectorAll(".dropdown")).forEach(function (dropdown) {
      new DropdownComponent(dropdown);
    });
  }); // rattachement au contexte window pour pouvoir l'utiliser en dehors du JS

  window.DropdownComponent = DropdownComponent;

  var Selector = {
    PARENT: "select.form-control"
  };
  var CLASSNAMES = {
    empty: "form-control-empty"
  };

  var DropdownSelect = /*#__PURE__*/function () {
    var _proto = DropdownSelect.prototype;

    /**
     * Initialisation du fonctionnement JS pour le dropdown select
     *
     * @param container
     */
    _proto.init = function init(container) {
      var _this = this;

      this.container = container;

      this._onBlur = function () {
        if (_this.container.value !== "" && _this.container.classList.contains(CLASSNAMES.empty)) {
          // la liste déroulante a maintenant une valeur sélectionnée,
          // on peut supprimer la classe gérant la bonne disposition des éléments
          // le label est donc juste au-dessus de la liste déroulante et donc de la valeur sélectionnée
          _this.container.classList.remove(CLASSNAMES.empty);
        } else if (_this.container.value === "" && !_this.container.classList.contains(CLASSNAMES.empty)) {
          // la liste déroulante n'a pas de valeur sélectionnée
          // on rajoute la classe pour que le label s'affiche au
          _this.container.classList.add(CLASSNAMES.empty);
        }
      };

      this.container.addEventListener("blur", this._onBlur);
    }
    /**
     * Construteur
     *
     * The constructor should only contain the boiler plate code for finding or creating the reference.
     *
     * @param container
     * @return {*}
     */
    ;

    function DropdownSelect(container) {
      if (container) {
        if (typeof container.dataset.ref === "undefined") {
          this.ref = Math.random();
          DropdownSelect.refs[this.ref] = this;
          container.dataset.ref = this.ref;
          this.init(container);
        } else {
          // If this element has already been instantiated, use the existing reference.
          return DropdownSelect.refs[container.dataset.ref];
        }
      }
    }
    /**
     * Décharge le composant
     */


    _proto.dispose = function dispose() {
      this.container.removeEventListener("blur", this._onBlur);
    };

    return DropdownSelect;
  }();

  DropdownSelect.refs = {};
  document.addEventListener("DOMContentLoaded", function () {
    var dropdowns = document.querySelectorAll(Selector.PARENT);
    [].forEach.call(dropdowns, function (dropdown) {
      new DropdownSelect(dropdown);
    });
  }); // rattachement au contexte window pour pouvoir l'utiliser en dehors du JS

  window.DropdownSelect = DropdownSelect;

  var classes$2 = {
    selected: "ob1-filterchip-selected"
  }; // les textes qui peuvent être utilisés dans le composant

  var text = {
    more_title: "Plus de filtres",
    more_title_small: "Filtres",
    btn_result_default: "Afficher les résultats",
    btn_result_none: "Aucun résultat",
    btn_result_one: "Afficher le résultat",
    btn_result: "Afficher les (x) résultats"
  }; // la liste des sélecteurs que l'on utilise dans le code du composant

  var selector$2 = {
    item: ".ob1-filterchip .ob1-filterchip-input",
    item_selected: ".ob1-filterchip .ob1-filterchip-input:checked",
    item_all: ".ob1-filterchip:first-child .ob1-filter-chips-bar-btn",
    item_selected_hidden: ".ob1-filterchip.sr-only .ob1-filterchip-input:checked"
  };

  var FilterChipsBar = /*#__PURE__*/function (_Ob1Component) {
    _inheritsLoose(FilterChipsBar, _Ob1Component);

    function FilterChipsBar(container, parameters) {
      return _Ob1Component.call(this, container, "FilterChipsBar", parameters) || this;
    }
    /**
     * Les paramètres par défaut du composant
     * Ils sont surchargés (par ordre de priorité) par :
     * - l'attribut data sur le noeud DOM du composant
     * - les paramètres utilisés au moment de l'instanciation
     * @returns {{unique: boolean}}
     */


    FilterChipsBar.getDefaultParams = function getDefaultParams() {
      return {
        unique: false
      };
    }
    /**
     * Initialisation du composant filter chips
     *
     * @param {HTMLElement} container le noeud DOM sur lequel est instancié le composant
     * @param {object} parameters les paramètres de ce composant
     */
    ;

    var _proto = FilterChipsBar.prototype;

    _proto.init = function init(container, parameters) {
      var _this = this;

      // on appelle la méthode d'initialisation d'Ob1Component (obligatoire)
      _Ob1Component.prototype.init.call(this, container, parameters);
      /**
       * Les éléments de filtre "simple" (tous sauf "tous / toutes")
       * @var {Array}
       */


      this.items = [];
      /**
       * Le filtre "spécial" "tous / toutes"
       * @var {HTMLElement}
       */

      this.itemAll = null;
      /**
       * Le filtre "spécial" "plus de filtres"
       * @var {HTMLElement}
       */

      this.itemMore = null;
      /**
       * Le label du filtre "spécial" "plus de filtres"
       */

      this.itemMoreLabel = text.more_title;
      /**
       * Le label du bouton "Afficher les résultats"
       */

      this.resultsDefaultButtonLabel = text.btn_result_default;
      this.resultsNoneButtonLabel = text.btn_result_none;
      this.resultsOneButtonLabel = text.btn_result_one;
      this.resultsButtonLabel = text.btn_result;
      /**
       * La référence vers la modal qui peut être générée
       * @var {HTMLElement}
       */

      this.modal = null;
      this.hTimeOut = null;
      /**
       * Toutes les méthodes ou fonctions qui sont sensées être appelées pour donner la liste des filter chips sélectionnées
       * @type {Array}
       */

      this.onUpdateValuesMethods = [];
      this.setCountResultFct(function () {
        return false;
      }); // traitement des filter chips "classiques"

      var filterChipsBarItem = this.container.querySelectorAll(selector$2.item);
      [].forEach.call(filterChipsBarItem, function (item) {
        _this.items.push(item);
      }); // traitement du filter chips spécial "tous / toutes"

      this.itemAll = this.container.querySelector(selector$2.item_all); // on crée le filter chip "plus de filtre"
      // => d'abord le container (on se base sur le type de tag des autres noeuds

      var itemMoreContainer = document.createElement(this.items[0].parentNode.tagName);
      itemMoreContainer.classList.add("ob1-filterchip", "d-none"); // => puis le bouton en lui même

      this.itemMore = document.createElement("button"); // ajout des classes spécifiques pour le filtre "plus de filtres"

      this.itemMore.classList.add("ob1-filterchip-label", "ob1-filter-chips-bar-btn");
      this.itemMore.setAttribute("type", "button");
      this.itemMore.setAttribute("title", "affiche l'intégralité des filtres disponibles");

      this._updateItemLabelAndDataTitle(this.itemMore, "" + this.itemMoreLabel);

      itemMoreContainer.appendChild(this.itemMore);
      this.container.appendChild(itemMoreContainer);

      this._addEvents();

      this.resize(); // a la fin de l'initialisation, on envoie le status du container pour indiquer les filtres activés

      this.triggerValuesEvent();
    }
    /**
     * Décharge le composant
     */
    ;

    _proto.dispose = function dispose() {
      // suppression de tous les event listeners qui ont été créés
      this.container.removeEventListener("change", this._onChange);
      this.container.removeEventListener("click", this._onClicked);
      window.removeEventListener("resize", this._onResize); // on remet l'affichage d'origine des différentes chips

      this.itemMore.parentNode.removeChild(this.itemMore);
      this.items.map(function (item) {
        item.parentNode.classList.remove("sr-only");
        item.setAttribute("tabindex", 0); // pour l'accessibilité
      }); // on appelle la méthode de suppression de composant d'Ob1Component (obligatoire)

      _Ob1Component.prototype.dispose.call(this);
    }
    /**
     * Redimensionnement du filter chip bar en fonction de la place disponible
     */
    ;

    _proto.resize = function resize() {
      this.itemMore.parentNode.classList.remove("d-none");
      this.itemMore.parentNode.classList.add("d-block");

      if (this.isMobile()) {
        // en mobile, tous les filtres sont masqués
        // seul le filter chip "Plus de filtres" est visible
        this.items.map(function (item) {
          item.parentNode.classList.add("sr-only");
          item.setAttribute("tabindex", -1); // pour l'accessibilité
        });
      } else {
        var isHidden = false; // en desktop, on affiche les filtres sur une seule ligne, ceux qui sont à la ligne sont masqués
        // ci dessous, code bof bof: je mets un texte plus long (pire cas) car le texte de "Plus de filtres"
        //   est complété avec le nombre d'éléments masqués
        //   ce qui le rendra plus long et peut donc avoir un impact sur la position des items

        this._updateItemLabelAndDataTitle(this.itemMore, this.itemMoreLabel + " (xx)"); // on réaffiche tous les éléments du composant


        this.items.map(function (item) {
          item.parentNode.classList.remove("sr-only");
          item.setAttribute("tabindex", 0); // pour l'accessibilité
        }); // calcul de la largeur maximale du container

        var containerOffsetTop = this.container.offsetTop;
        var itemMoreOffsetTop = this.itemMore.parentNode.offsetTop;
        var index = this.items.length - 1; // tant que "plus de filtres" est à la ligne, on masque des items (en partant de la fin)

        while (index >= 0 && // il y a encore au moins un élément qui peut être masqué
        itemMoreOffsetTop > containerOffsetTop // le filter chip "plus de filtres" n'est pas à la même hauteur que le container
        ) {
          var item = this.items[index--];
          item.parentNode.classList.add("sr-only");
          item.setAttribute("tabindex", -1); // pour l'accessibilité

          itemMoreOffsetTop = this.itemMore.parentNode.offsetTop; // la position du filter chip "plus de filtres" peut avoir évolué

          isHidden = true;
        }

        if (!isHidden) {
          // aucun élément n'est masqué
          // => on n'affiche plus le filter chip "plus de filtres"
          this.itemMore.parentNode.classList.remove("d-block");
          this.itemMore.parentNode.classList.add("d-none");
        }
      }

      this._updateSpecialChipDisplay();
    }
    /**
     * Met à jour l'affichage des chips spéciales :
     * - filter chip "plus de filtres" pour lister les éléments non affichés
     * - filter chip "tous / toutes" pour sélectionner tous / toutes
     * @private
     */
    ;

    _proto._updateSpecialChipDisplay = function _updateSpecialChipDisplay() {
      // filter chip "plus de filtres"
      var chipHiddenSelected = this.container.querySelectorAll(selector$2.item_selected_hidden);
      var countHiddenSelected = chipHiddenSelected.length;
      var textMore = this.isMobile() ? text.more_title_small : this.itemMoreLabel;

      if (countHiddenSelected > 0) {
        this._updateItemLabelAndDataTitle(this.itemMore, textMore + " (" + countHiddenSelected + ")");

        this.itemMore.parentNode.classList.add(classes$2.selected);
      } else {
        this._updateItemLabelAndDataTitle(this.itemMore, "" + textMore);

        this.itemMore.parentNode.classList.remove(classes$2.selected);
      } // filter chip "tous / toutes"


      var chipsChecked = this.items.filter(function (chip) {
        return chip.checked === true;
      });

      if (this.itemAll) {
        if (chipsChecked.length === 0) {
          this.itemAll.parentNode.classList.add(classes$2.selected);
        } else if (chipsChecked.length < this.items.length) {
          this.itemAll.parentNode.classList.remove(classes$2.selected);
        }
      }
    }
    /**
     * met à jour le contenu du bouton de la modal pour afficher le nombre de résultat
     * @private
     */
    ;

    _proto._updateBtnDisplay = function _updateBtnDisplay() {
      var selectedValues = [];
      var modalFilterChips = this.modal.querySelectorAll(selector$2.item_selected);
      [].forEach.call(modalFilterChips, function (item) {
        selectedValues.push(item.value);
      }); // récupération du nombre de résultats potentiels (fourni par le service)

      var count = this.displayCountFct(selectedValues);
      var btnNode = this.modal.querySelector(".modal-footer .btn"); // mise à jour du texte du bouton en fonction du nombre de résultats potentiels

      var btnTxt = "";

      if (btnNode) {
        switch (count) {
          case false:
            btnTxt = this.resultsDefaultButtonLabel;
            break;

          case 0:
            btnTxt = this.resultsNoneButtonLabel;
            break;

          case 1:
            btnTxt = this.resultsOneButtonLabel;
            break;

          default:
            btnTxt = this.resultsButtonLabel.replace("(x)", count);
            break;
        }
      }

      btnNode.innerText = btnTxt;
    }
    /**
     * Envoie les valeurs des filter chips sélectionnées pour le composant
     * @return {FilterChipsBar}
     */
    ;

    _proto.triggerValuesEvent = function triggerValuesEvent() {
      if (this.onUpdateValuesMethods.length > 0) {
        // on a au moins une méthode à appeler, donc on récupère le statut
        var results = this._getSelectedValues();

        this.onUpdateValuesMethods.forEach(function (onMethod) {
          onMethod(results);
        });
      }

      return this;
    }
    /**
     * Retourne un tableau contenant la liste des valeurs des filter chips sélectionnés
     * @return {string[]}
     * @private
     */
    ;

    _proto._getSelectedValues = function _getSelectedValues() {
      var filterChipsSelected = this.items;
      filterChipsSelected = filterChipsSelected.filter(function (item) {
        return item.checked === true;
      });
      return filterChipsSelected.map(function (item) {
        return item.value;
      });
    }
    /**
     * Gestion des événements sur le composant
     * @private
     */
    ;

    _proto._addEvents = function _addEvents() {
      var _this2 = this;

      // création de tous les handlers d'événements
      // @see dispose() : ces handlers sont utilisés pour la déconnexion des événements
      this._onChange = function () {
        // pour éviter le déclenchement multiple quand on fait le changement sur plusieurs checkbox en même temps
        // ex: depuis la modal
        // => on simule un debounce
        clearTimeout(_this2.hTimeOut);
        _this2.hTimeOut = setTimeout(function () {
          _this2._updateSpecialChipDisplay();

          _this2.triggerValuesEvent();
        }, 10);
      };

      this._onClicked = function (event) {
        if (event.target === _this2.itemAll) {
          // on a cliqué sur le bouton "Tous / toutes"
          event.preventDefault();

          if (!_this2.itemAll.parentNode.classList.contains(classes$2.selected)) {
            _this2.items.map(function (item) {
              return item.checked = false;
            });

            _this2._updateSpecialChipDisplay();

            _this2.triggerValuesEvent();
          }
        } else if (event.target === _this2.itemMore) {
          // on a cliqué sur le bouton "Plus de filtres"
          event.preventDefault();

          _this2._displayModal();
        }
      };

      this._onResize = function () {
        clearTimeout(_this2.resizetimeout);
        _this2.resizetimeout = setTimeout(function () {
          _this2.resize();
        }, 50);
      }; // un changement a eu lieu sur l'une des cases à cocher


      this.container.addEventListener("change", this._onChange); // on a cliqué sur le container

      this.container.addEventListener("click", this._onClicked); // on recalcule les éléments à afficher dans le fil d'Ariane au redimensionnement de la fenêtre

      window.addEventListener("resize", this._onResize);
    }
    /**
     * Affiche la modal pour afficher la liste de tous les filter chips disponibles
     * @private
     */
    ;

    _proto._displayModal = function _displayModal() {
      var _this3 = this;

      if (!this.modal) {
        // la modal n'a jamais été affichée, on génère la carcasse dynamiquement
        this.modal = document.createElement("div");
        this.modal.innerHTML = "\n        <div class=\"modal fade\" tabindex=\"-1\" role=\"dialog\" aria-hidden=\"true\">\n          <div class=\"modal-dialog\" role=\"document\">\n            <div class=\"modal-content\">\n              <div class=\"modal-header\">\n                <button type=\"button\" class=\"close d-none d-md-block\" data-dismiss=\"modal\" aria-label=\"Fermer\">\n                  <span aria-hidden=\"true\">&times;</span>\n                </button>\n                <button type=\"button\" class=\"close d-md-none o-link-arrow o-link-small back\" data-dismiss=\"modal\">\n                  Retour</button>\n              </div>\n              <div class=\"modal-body flex-row flex-wrap flex-grow-0\">\n                <h3 class=\"h4 mb-1 mb-md-2\"></h3>\n                <ul class=\"ob1-filter-chips-bar mb-0\"></ul>\n                <button type=\"button\" class=\"btn btn-link ob1-link-icon p-0 mb-2\">\n                  <span class=\"icon icon-delete\" aria-hidden=\"true\"></span>\n                  <span class=\"ob1-link-icon-text\">Effacer</span>\n                </button>\n              </div>\n              <div class=\"modal-footer\">\n                <button type=\"button\" class=\"btn btn-secondary\"></button>\n              </div>\n            </div>\n          </div>\n        </div>";
        document.body.appendChild(this.modal);
        $(this.modal.firstElementChild).on("show.bs.modal", function () {
          // la modal s'affiche, on met à jour le contenu pour prendre le statut courant des filter chips de la page
          var modalChipsList = _this3.modal.querySelector(".modal-body .ob1-filter-chips-bar");

          _this3.items.forEach(function (filterChipElement) {
            var filterChipElementClone = filterChipElement.parentNode.cloneNode(true);
            filterChipElementClone.classList.remove("sr-only");
            filterChipElementClone.firstElementChild.setAttribute("tabindex", "0"); // les inputs / labels ont été cloné, mais il faut penser à modifier les identifiants des checkbox

            filterChipElementClone.firstElementChild.id += "tmp";
            filterChipElementClone.lastElementChild.setAttribute("for", filterChipElementClone.lastElementChild.getAttribute("for") + "tmp");
            modalChipsList.appendChild(filterChipElementClone);
          }); // on met à jour le texte du bouton


          _this3._updateBtnDisplay(); // on met à jour le titre de la modal


          var modalTitle = _this3.modal.querySelector(".modal-body .h4");

          if (_this3.isMobile()) {
            modalTitle.innerText = text.more_title_small;
          } else {
            modalTitle.innerText = _this3.itemMoreLabel;
          }

          var ariaLabel = _this3.container.getAttribute("aria-label");

          if (ariaLabel) {
            modalTitle.setAttribute("aria-label", ariaLabel);
          }
        }).on("hidden.bs.modal", function () {
          // quand la modal est fermée, on vide le contenu, donc les anciennes filter chips...
          // c'est plus simple que de les mettre à jour
          var modalChipsList = _this3.modal.querySelector(".modal-body .ob1-filter-chips-bar");

          modalChipsList.innerHTML = "";

          _this3._focus();
        }).on("change", ".modal-body", function (event) {
          event.preventDefault(); // on met à jour le texte du bouton

          _this3._updateBtnDisplay();
        }).on("click", ".modal-body .btn", function () {
          // clic sur le bouton de désactivation des filtres
          var filterChipsBarSelectedItems = _this3.modal.querySelectorAll(selector$2.item_selected);

          [].forEach.call(filterChipsBarSelectedItems, function (item) {
            // la simulation du clic va propager l'événement jusqu'au container ou il sera traité
            item.click();
          });
        }).on("click", ".modal-footer", function () {
          // clic sur le bouton de validation
          // on répercute les modifications de filtre de la modal, pour les mettre dans la page principale
          var filterChipsBarItem = _this3.modal.firstElementChild.querySelectorAll(selector$2.item);

          [].forEach.call(filterChipsBarItem, function (item, index) {
            if (_this3.items[index].checked !== item.checked) {
              // la simulation du clic va propager l'événement jusqu'au container ou il sera traité
              _this3.items[index].click();
            }
          }); // fermeture de la modal et on remet le focus sur la page principale au niveau du filter chips bar

          $(_this3.modal.firstElementChild).modal("hide");

          _this3._focus();
        });
      }

      $(this.modal.firstElementChild).modal();
    }
    /**
     * Met le focus sur le meilleur élément du composant
     * @private
     */
    ;

    _proto._focus = function _focus() {
      var selectedItems = this.container.querySelectorAll(selector$2.item_selected);

      if (selectedItems.length > 0) {
        // on met le focus sur le dernier filtre sélectionné
        selectedItems[selectedItems.length - 1].focus();
      } else {
        // si aucun élément n'est sélectionné, on met le focus sur le bouton tous / toutes
        this.itemAll.focus();
      }
    }
    /**
     * Connecte une fonction pour qu'elle recoive la liste des valeurs des filter chips sélectionnés
     *
     * exemple :
     * // @type {Array} filterChipStatus
     * var updateStatus = function(filterChipStatus) {
     *   console.debug(filterChipStatus)
     * }
     *
     * // instanciation du composant :
     * var node = document.getElementById('myFilterChipsBar');
     * var filterChipBar = new FilterChipsBar(node);
     *
     * // On peut utiliser le composant en lui-même pour définir la fonction d'appel :
     * filterChipBar.onUpdateValues(updateStatus)
     *
     * // On peut aussi passer par l'intermédiaire du noeud DOM :
     * node.filterChipsBar('onUpdateValues', updateStatus)
     *
     * @param {Function} fct La fonction à appeler quand la liste des filter chips a changé
     * @return {FilterChipsBar}
     */
    ;

    _proto.onUpdateValues = function onUpdateValues(fct) {
      this.onUpdateValuesMethods.push(fct);
      return this;
    }
    /**
     * Permet de définir la fonction qui sera appelée pour indiquer le nombre de résultat qui seront affichés
     * en fonction des filtres actuellement sélectionnés.
     *
     * @param {Function} fct La fonction à appeler pour connaître le nombre de résultat. Cette fonction :
     * - prendra en entrée un tableau de valeurs (string[])
     * - retournera soit :
     *  - un entier : le nombre de résultats
     *  - false : pour afficher le texte par défaut
     * @return {FilterChipsBar}
     */
    ;

    _proto.setCountResultFct = function setCountResultFct(fct) {
      this.displayCountFct = fct;
      return this;
    }
    /**
     * Permet de définir le texte à afficher dans le chip "Plus de filtres".
     *
     * @param {String} str le texte à afficher dans le chip "Plus de filtres"
     */
    ;

    _proto.setItemMoreLabel = function setItemMoreLabel(str) {
      this.itemMoreLabel = str;

      this._updateItemLabelAndDataTitle(this.itemMore, this.itemMoreLabel);

      return this;
    }
    /**
     * Permet de définir le texte à afficher dans le bouton "Afficher le/les/X résultat(s)".
     *
     * @param {String} results le texte à utiliser à la place de "résultats"
     * @param {String} result le texte à utiliser à la place de "résultat"
     */
    ;

    _proto.setResultsButtonLabels = function setResultsButtonLabels(results, result) {
      this.resultsDefaultButtonLabel = text.btn_result_default.replace("résultats", results);
      this.resultsNoneButtonLabel = text.btn_result_none.replace("résultat", result);
      this.resultsOneButtonLabel = text.btn_result_one.replace("résultat", result);
      this.resultsButtonLabel = text.btn_result.replace("résultats", results);
      return this;
    }
    /**
     * Modifie l'innerHTML d'un élément selon un label donné et ajoute un attribut data-title
     * avec pour valeur ce même label (nécessaire pour l'élément chips)
     *
     * @param {HTMLElement} item  l'élement HRML à modifier
     * @param {String} label      le label à ajouter en innerHTML et en data-title
     */
    ;

    _proto._updateItemLabelAndDataTitle = function _updateItemLabelAndDataTitle(item, label) {
      item.innerHTML = label;
      item.setAttribute("data-title", label);
    };

    return FilterChipsBar;
  }(Ob1Component); // rattachement au contexte window pour pouvoir l'utiliser en dehors du JS


  window.FilterChipsBar = FilterChipsBar;

  var FormControlClear = /*#__PURE__*/function (_Ob1Component) {
    _inheritsLoose(FormControlClear, _Ob1Component);

    function FormControlClear(container, parameters) {
      return _Ob1Component.call(this, container, "FormControlClear", parameters) || this;
    }
    /**
     * Initialisation du composant FormControlClear
     *
     * @param {HTMLElement} container le noeud DOM sur lequel est instancié le composant
     * @param {object} parameters les paramètres de ce composant
     */


    var _proto = FormControlClear.prototype;

    _proto.init = function init(container, parameters) {
      _Ob1Component.prototype.init.call(this, container, parameters);

      this.clearIcon = this.container.parentElement.querySelector(".btn-clear");

      this._addEvents();
    }
    /**
     * Gestion des événements sur le composant
     * @private
     */
    ;

    _proto._addEvents = function _addEvents() {
      var _this = this;

      this._onInput = function () {
        if (!!_this.container.value) {
          _this.clearIcon.style.display = "inline-block";
        } else {
          _this.clearIcon.style.display = "none";
        }
      };

      this.container.addEventListener("input", this._onInput);

      this._onClick = function () {
        _this.container.value = "";
        _this.clearIcon.style.display = "none";

        _this.container.focus();
      };

      this.clearIcon.addEventListener("click", this._onClick);
    }
    /**
     * Décharge le composant
     */
    ;

    _proto.dispose = function dispose() {
      // suppression de tous les event listeners qui ont été créés
      this.container.removeEventListener("input", this._onInput);
      this.container.removeEventListener("click", this._onClick); // on appelle la méthode de suppression de composant d'Ob1Component (obligatoire)

      _Ob1Component.prototype.dispose.call(this);
    };

    return FormControlClear;
  }(Ob1Component); // rattachement au contexte window pour pouvoir l'utiliser en dehors du JS


  window.FormControlClear = FormControlClear;

  var classes$3 = {
    empty: "form-control-empty"
  };

  var FormControlEmpty = /*#__PURE__*/function (_Ob1Component) {
    _inheritsLoose(FormControlEmpty, _Ob1Component);

    function FormControlEmpty(container, parameters) {
      return _Ob1Component.call(this, container, "FormControlEmpty", parameters) || this;
    }
    /**
     * Initialisation du composant FormcontrolEmpty
     *
     * @param {HTMLElement} container le noeud DOM sur lequel est instancié le composant
     * @param {object} parameters les paramètres de ce composant
     */


    var _proto = FormControlEmpty.prototype;

    _proto.init = function init(container, parameters) {
      // on appelle la méthode d'initialisation d'Ob1Component (obligatoire)
      _Ob1Component.prototype.init.call(this, container, parameters);

      this._addEvents();
    }
    /**
     * Décharge le composant
     */
    ;

    _proto.dispose = function dispose() {
      // suppression de tous les event listeners qui ont été créés
      this.container.removeEventListener("blur", this._hOnBlur); // on appelle la méthode de suppression de composant d'Ob1Component (obligatoire)

      _Ob1Component.prototype.dispose.call(this);
    }
    /**
     * Gestion des événements sur le composant
     * @private
     */
    ;

    _proto._addEvents = function _addEvents() {
      var _this = this;

      // création de tous les handlers d'événements
      // @see dispose() : ces handlers sont utilisés pour la déconnexion des événements
      this._hOnBlur = function () {
        if (_this.container.value !== "" && _this.container.classList.contains(classes$3.empty)) {
          // l'élément a maintenant une valeur non nulle,
          // on peut supprimer la classe gérant la bonne disposition des éléments
          // le label est donc juste au-dessus de la liste déroulante et donc de la valeur sélectionnée
          _this.container.classList.remove(classes$3.empty);
        } else if (_this.container.value === "" && !_this.container.classList.contains(classes$3.empty)) {
          // la liste déroulante n'a pas de valeur sélectionnée
          // on rajoute la classe pour que le label s'affiche au
          _this.container.classList.add(classes$3.empty);
        }
      }; // un changement a eu lieu sur l'une des cases à cocher


      this.container.addEventListener("blur", this._hOnBlur);
    };

    return FormControlEmpty;
  }(Ob1Component); // rattachement au contexte window pour pouvoir l'utiliser en dehors du JS


  window.FormControlEmpty = FormControlEmpty;

  var megamenu = createCommonjsModule(function (module, exports) {
  /*!
    * Boosted v4.3.1 (https://boosted.orange.com)
    * Copyright 2014-2019 The Boosted Authors
    * Copyright 2014-2019 Orange
    * Licensed under MIT (https://github.com/orange-opensource/orange-boosted-bootstrap/blob/master/LICENSE)
    * This a fork of Bootstrap : Initial license below
    * Bootstrap megamenu.js v4.3.1 (https://boosted.orange.com)
    * Copyright 2011-2019 The Boosted Authors (https://github.com/Orange-OpenSource/Orange-Boosted-Bootstrap/graphs/contributors)
    * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
    */
  (function (global, factory) {
     module.exports = factory(jquery, util) ;
  }(commonjsGlobal, function ($, Util) {
    $ = $ && $.hasOwnProperty('default') ? $['default'] : $;
    Util = Util && Util.hasOwnProperty('default') ? Util['default'] : Util;

    function _defineProperties(target, props) {
      for (var i = 0; i < props.length; i++) {
        var descriptor = props[i];
        descriptor.enumerable = descriptor.enumerable || false;
        descriptor.configurable = true;
        if ("value" in descriptor) descriptor.writable = true;
        Object.defineProperty(target, descriptor.key, descriptor);
      }
    }

    function _createClass(Constructor, protoProps, staticProps) {
      if (protoProps) _defineProperties(Constructor.prototype, protoProps);
      if (staticProps) _defineProperties(Constructor, staticProps);
      return Constructor;
    }

    /* eslint no-magic-numbers: ["error", { "ignore": [1,2] }] */

    /**
     * ------------------------------------------------------------------------
     * Constants
     * ------------------------------------------------------------------------
     */

    var NAME = 'megamenu';
    var VERSION = '4.3.1';
    var DATA_KEY = 'bs.megamenu';
    var JQUERY_NO_CONFLICT = $.fn[NAME];
    var ARROW_LEFT_KEYCODE = 37; // KeyboardEvent.which value for left arrow key

    var ARROW_RIGHT_KEYCODE = 39; // KeyboardEvent.which value for right arrow key

    var ARROW_UP_KEYCODE = 38; // KeyboardEvent.which value for up arrow key

    var ARROW_DOWN_KEYCODE = 40; // KeyboardEvent.which value for down arrow key

    var TIMEOUT = 1000; // Timeout befor focusing first element

    var PERCENTAGE = 100; // Width slide proportion

    var SPLITLENGHT = 4;
    var ClassName = {
      TRANSITIONING: 'transitioning'
    };
    var Selector = {
      MEGAMENU: '.mega-menu',
      ROOT_NAV: '.mega-menu > .navbar-nav',
      MEGAMENU_PANEL: '.mega-menu-panel',
      MEGAMENU_NAV: '.nav-link + .navbar-nav',
      NAV_MENU: '.navbar-nav',
      NAV_ITEM: '.nav-item',
      NAV_LINK: '.nav-link',
      NAV_LINK_COLLAPSE: '.nav-link[data-toggle=collapse]',
      NAV_LINK_BACK: '.nav-link.back',
      NAV_LINK_EXPANDED: '.nav-link[aria-expanded=true]'
      /**
       * ------------------------------------------------------------------------
       * Class Definition
       * ------------------------------------------------------------------------
       */

    };

    var MegaMenu =
    /*#__PURE__*/
    function () {
      function MegaMenu(element, config) {
        this._element = element;
        this._$navLinks = $(this._element).find(Selector.NAV_LINK);
        this._$goForwardLinks = $(this._element).find(Selector.MEGAMENU_NAV).prev(Selector.NAV_LINK);
        this._$goBackLinks = $(this._element).find(Selector.NAV_LINK_BACK);
        this._$topCollapseMenus = $(this._element).find(Selector.MEGAMENU_PANEL);
        this._$navLinkCollapses = $(this._element).find(Selector.NAV_LINK_COLLAPSE);
        this._config = config;

        if (typeof this._config.noFocus === 'undefined') {
          this._config.noFocus = false;
        }

        this._addEventListeners();

        this._addAriaAttributes(this._element);

        this.goTo = this._initPosition;
      } // getters


      var _proto = MegaMenu.prototype;

      // public
      // private
      _proto._addEventListeners = function _addEventListeners() {
        var _this = this;

        this._$goForwardLinks.on('click', function (event) {
          return _this._goForward(event);
        });

        this._$goBackLinks.on('click', function (event) {
          return _this._goBackward(event);
        });

        this._$navLinks.on('keydown', function (event) {
          return _this._manageKeyDown(event);
        });

        if (!this._config.noFocus) {
          this._$topCollapseMenus.on('shown.bs.collapse', this._collapseFocus);
        }

        this._$navLinkCollapses.on('click', function (event) {
          return _this._handleCollapseToggle(event);
        });
      };

      _proto._addAriaAttributes = function _addAriaAttributes(element) {
        var $subNavs = $(element).find('.nav-link + .navbar-nav');
        $(element).attr('role', 'application');
        $(element).find('> .navbar-nav').attr('role', 'menu');
        $(element).find(Selector.MEGAMENU_PANEL).attr('role', 'menu');
        $(element).find('.nav-link[data-toggle=collapse]').attr('role', 'menuitem');
        $(element).find(Selector.NAV_LINK_BACK).attr({
          'aria-hidden': true
        });
        $(element).find(Selector.NAV_ITEM).attr('role', 'presentation');
        $subNavs.each(function () {
          var navId = Util.getUID(NAME);
          var $thisNavToggler = $(this).prev(Selector.NAV_LINK);
          var $thisNav = $(this);
          var $thisNavBackLink = $thisNav.find(Selector.NAV_LINK_BACK);
          var $topMenu = $(this).closest(Selector.NAV_MENU).parent().closest(Selector.NAV_MENU).prev(Selector.NAV_LINK);
          var goBackLabel = "go back to " + $topMenu.text() + " menu";

          if (!$topMenu.length) {
            goBackLabel = "go back to " + $(this).closest(Selector.MEGAMENU_PANEL).prev(Selector.NAV_LINK).text() + " menu";
          }

          $thisNav.attr({
            id: navId,
            role: 'menu'
          });
          $thisNavToggler.attr({
            role: 'menuitem',
            'aria-controls': navId,
            'aria-expanded': false,
            'aria-haspopup': true
          });
          $thisNavBackLink.attr({
            role: 'menuitem',
            'aria-controls': navId,
            'aria-label': goBackLabel
          });
        });
      };

      _proto._initPosition = function _initPosition(target) {
        var _this2 = this;

        if (!$(target).length) {
          return;
        }

        var $target = $(target).first();
        var position = $target.parents().index(this._element);
        var rootPosition = $('.mega-menu-panel .nav-link').first().parents().index($('.mega-menu'));
        var translatePercentage = -(position - rootPosition) * PERCENTAGE / 2;
        var $thisNav = $target.closest(Selector.NAV_MENU);
        var $rootNav = $(Selector.ROOT_NAV);
        $rootNav.addClass(ClassName.TRANSITIONING); // open collapse

        if ($target.attr('data-toggle') === 'collapse') {
          $target.siblings(Selector.MEGAMENU_PANEL).collapse('show');

          this._$topCollapseMenus.not($target.siblings(Selector.MEGAMENU_PANEL)).collapse('hide');

          $(this._element).height('auto');
          $rootNav.css('transform', 'translateX(0%)');
        } else {
          $target.closest(Selector.MEGAMENU_PANEL).collapse('show');

          this._$topCollapseMenus.not($target.closest(Selector.MEGAMENU_PANEL)).collapse('hide'); // show menu and hide other


          $target.parents(Selector.NAV_MENU).show(); // set aria on parent links

          $target.parents(Selector.NAV_ITEM).find('> .nav-link').not($target).attr({
            tabindex: -1,
            'aria-hidden': true,
            'aria-expanded': true
          }); // translate to pos

          $rootNav.css('transform', "translateX(" + translatePercentage + "%)");

          if (translatePercentage) {
            // adapt main collapse height to target height
            $(this._element).height($thisNav.height());
          } else {
            $(this._element).height('auto');
          }
        } // set focus on target link


        setTimeout(function () {
          if (!_this2._config.noFocus) {
            // set focus on target link
            $target.trigger('focus');
          }

          $rootNav.removeClass(ClassName.TRANSITIONING);
        }, TIMEOUT);
      };

      _proto._manageKeyDown = function _manageKeyDown(event) {
        var $thisTarget = $(event.target); // test key code

        if (/input|textarea/i.test(event.target.tagName)) {
          return;
        } // proceed according to key code


        switch (event.which) {
          case ARROW_LEFT_KEYCODE:
            this._goBackward(event);

            break;

          case ARROW_RIGHT_KEYCODE:
            this._goForward(event);

            break;

          case ARROW_UP_KEYCODE:
            // focus prev nav link
            $thisTarget.parent().prev().find('>.nav-link').not(Selector.NAV_LINK_BACK).trigger('focus');
            break;

          case ARROW_DOWN_KEYCODE:
            // focus next nav link
            $thisTarget.parent().next().find('>.nav-link').trigger('focus');
            break;
        }
      };

      _proto._collapseFocus = function _collapseFocus() {
        $(this).find(Selector.NAV_LINK).not(Selector.NAV_LINK_BACK).first().trigger('focus');
      };

      _proto._handleCollapseToggle = function _handleCollapseToggle(e) {
        var $this = $(e.target);
        var $thisCollapse = $($this.attr('href'));

        this._$topCollapseMenus.not($thisCollapse).collapse('hide');
      };

      _proto._goForward = function _goForward(e) {
        e.preventDefault();
        var $this = $(e.target);
        var $thisNav = $this.closest(Selector.NAV_MENU);
        var $targetNav = $this.next(Selector.NAV_MENU);
        var $rootNav = $(Selector.ROOT_NAV);
        var $thisNavToggler = $this;
        var currentTranslatePos = parseInt($rootNav.css('transform').split(',')[SPLITLENGHT], 10);
        var navWidth = $rootNav.width();
        var currentTranslatePercentage = PERCENTAGE * currentTranslatePos / navWidth;

        if (!$this.next(Selector.NAV_MENU).length || $rootNav.hasClass(ClassName.TRANSITIONING)) {
          return false;
        }

        $rootNav.addClass(ClassName.TRANSITIONING); // hide all nav on same level

        $thisNav.find(Selector.NAV_MENU).hide(); // show target navbar-nav

        $targetNav.show(); // adapt main collapse height to target height

        $(Selector.MEGAMENU).height($targetNav.height()); // make only visible elements focusable

        if (!currentTranslatePercentage) {
          $rootNav.find('>.nav-item .nav-link').attr({
            tabindex: -1,
            'aria-hidden': true
          });
        }

        $thisNav.find(Selector.NAV_LINK).attr({
          tabindex: -1,
          'aria-hidden': true
        });
        $targetNav.find(Selector.NAV_LINK).attr({
          tabindex: 0,
          'aria-hidden': false
        }); // translate menu

        $rootNav.css('transform', "translateX(" + (currentTranslatePercentage - PERCENTAGE) + "%)"); // focus on target nav first item

        $rootNav.one('transitionend', function () {
          $thisNavToggler.attr('aria-expanded', true);
          $targetNav.find(Selector.NAV_LINK).not(Selector.NAV_LINK_BACK).first().trigger('focus');
          $rootNav.removeClass(ClassName.TRANSITIONING);
        });
        return true;
      };

      _proto._goBackward = function _goBackward(e) {
        e.preventDefault();
        var $this = $(e.target);
        var $thisNav = $this.closest(Selector.NAV_MENU);
        var $targetNav = $thisNav.parent().closest(Selector.NAV_MENU);
        var $rootNav = $(Selector.ROOT_NAV);
        var $targetNavToggler = $targetNav.find(Selector.NAV_LINK_EXPANDED);
        var currentTranslatePos = parseInt($rootNav.css('transform').split(',')[SPLITLENGHT], 10);
        var navWidth = $rootNav.width();
        var currentTranslatePercentage = PERCENTAGE * currentTranslatePos / navWidth;

        if (!currentTranslatePercentage || $rootNav.hasClass(ClassName.TRANSITIONING)) {
          return false;
        }

        $rootNav.addClass(ClassName.TRANSITIONING); // make only visible elements focusable

        $targetNav.find(Selector.NAV_LINK).attr({
          tabindex: 0,
          'aria-hidden': false
        });

        if (currentTranslatePercentage === -PERCENTAGE) {
          // reset main collapse height
          $(Selector.MEGAMENU).css('height', 'auto');
          $rootNav.find('>.nav-item .nav-link').attr({
            tabindex: 0,
            'aria-hidden': false
          });
        } // translate menu


        $rootNav.css('transform', "translateX(" + (currentTranslatePercentage + PERCENTAGE) + "%)"); // focus on target nav first item

        $rootNav.one('transitionend', function () {
          $targetNavToggler.attr('aria-expanded', false);
          $targetNavToggler.trigger('focus');
          $thisNav.hide();
          $rootNav.removeClass(ClassName.TRANSITIONING);
        });
        return true;
      } // static
      ;

      MegaMenu._jQueryInterface = function _jQueryInterface(config) {
        return this.each(function () {
          if (!$(this).is(Selector.MEGAMENU)) {
            throw new TypeError('Element is not a mega menu');
          }

          if (!config) {
            config = {};
          } else if (config.noFocus && typeof config.noFocus !== 'boolean') {
            // param = true
            throw new TypeError('no-focus parameter must be boolean');
          }

          var data = $(this).data(DATA_KEY);

          if (!data) {
            data = new MegaMenu(this, config);
            $(this).data(DATA_KEY, data);
          }

          if (config.target) {
            if (typeof config.target !== 'string' || !/^[.#].*/.test(config.target)) {
              throw new TypeError("Selector \"" + config.target + "\" is not supported");
            }

            data.goTo(config.target);
          }
        });
      };

      _createClass(MegaMenu, null, [{
        key: "VERSION",
        get: function get() {
          return VERSION;
        }
      }]);

      return MegaMenu;
    }();
    /**
     * ------------------------------------------------------------------------
     * jQuery
     * ------------------------------------------------------------------------
     */


    $.fn[NAME] = MegaMenu._jQueryInterface;
    $.fn[NAME].Constructor = MegaMenu;

    $.fn[NAME].noConflict = function () {
      $.fn[NAME] = JQUERY_NO_CONFLICT;
      return MegaMenu._jQueryInterface;
    };

    return MegaMenu;

  }));

  });

  var modal = createCommonjsModule(function (module, exports) {
  /*!
    * Boosted v4.3.1 (https://boosted.orange.com)
    * Copyright 2014-2019 The Boosted Authors
    * Copyright 2014-2019 Orange
    * Licensed under MIT (https://github.com/orange-opensource/orange-boosted-bootstrap/blob/master/LICENSE)
    * This a fork of Bootstrap : Initial license below
    * Bootstrap modal.js v4.3.1 (https://boosted.orange.com)
    * Copyright 2011-2019 The Boosted Authors (https://github.com/Orange-OpenSource/Orange-Boosted-Bootstrap/graphs/contributors)
    * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
    */
  (function (global, factory) {
     module.exports = factory(jquery, util) ;
  }(commonjsGlobal, function ($, Util) {
    $ = $ && $.hasOwnProperty('default') ? $['default'] : $;
    Util = Util && Util.hasOwnProperty('default') ? Util['default'] : Util;

    function _defineProperties(target, props) {
      for (var i = 0; i < props.length; i++) {
        var descriptor = props[i];
        descriptor.enumerable = descriptor.enumerable || false;
        descriptor.configurable = true;
        if ("value" in descriptor) descriptor.writable = true;
        Object.defineProperty(target, descriptor.key, descriptor);
      }
    }

    function _createClass(Constructor, protoProps, staticProps) {
      if (protoProps) _defineProperties(Constructor.prototype, protoProps);
      if (staticProps) _defineProperties(Constructor, staticProps);
      return Constructor;
    }

    function _defineProperty(obj, key, value) {
      if (key in obj) {
        Object.defineProperty(obj, key, {
          value: value,
          enumerable: true,
          configurable: true,
          writable: true
        });
      } else {
        obj[key] = value;
      }

      return obj;
    }

    function _objectSpread(target) {
      for (var i = 1; i < arguments.length; i++) {
        var source = arguments[i] != null ? arguments[i] : {};
        var ownKeys = Object.keys(source);

        if (typeof Object.getOwnPropertySymbols === 'function') {
          ownKeys = ownKeys.concat(Object.getOwnPropertySymbols(source).filter(function (sym) {
            return Object.getOwnPropertyDescriptor(source, sym).enumerable;
          }));
        }

        ownKeys.forEach(function (key) {
          _defineProperty(target, key, source[key]);
        });
      }

      return target;
    }

    /**
     * ------------------------------------------------------------------------
     * Constants
     * ------------------------------------------------------------------------
     */

    var NAME = 'modal';
    var VERSION = '4.3.1';
    var DATA_KEY = 'bs.modal';
    var EVENT_KEY = "." + DATA_KEY;
    var DATA_API_KEY = '.data-api';
    var JQUERY_NO_CONFLICT = $.fn[NAME];
    var ESCAPE_KEYCODE = 27; // KeyboardEvent.which value for Escape (Esc) key

    var Default = {
      backdrop: true,
      keyboard: true,
      focus: true,
      show: true
    };
    var DefaultType = {
      backdrop: '(boolean|string)',
      keyboard: 'boolean',
      focus: 'boolean',
      show: 'boolean'
    };
    var Event = {
      HIDE: "hide" + EVENT_KEY,
      HIDDEN: "hidden" + EVENT_KEY,
      SHOW: "show" + EVENT_KEY,
      SHOWN: "shown" + EVENT_KEY,
      FOCUSIN: "focusin" + EVENT_KEY,
      RESIZE: "resize" + EVENT_KEY,
      CLICK_DISMISS: "click.dismiss" + EVENT_KEY,
      KEYDOWN_DISMISS: "keydown.dismiss" + EVENT_KEY,
      MOUSEUP_DISMISS: "mouseup.dismiss" + EVENT_KEY,
      MOUSEDOWN_DISMISS: "mousedown.dismiss" + EVENT_KEY,
      CLICK_DATA_API: "click" + EVENT_KEY + DATA_API_KEY
    };
    var ClassName = {
      SCROLLABLE: 'modal-dialog-scrollable',
      SCROLLBAR_MEASURER: 'modal-scrollbar-measure',
      BACKDROP: 'modal-backdrop',
      OPEN: 'modal-open',
      FADE: 'fade',
      SHOW: 'show'
    };
    var Selector = {
      DIALOG: '.modal-dialog',
      MODAL_BODY: '.modal-body',
      DATA_TOGGLE: '[data-toggle="modal"]',
      DATA_DISMISS: '[data-dismiss="modal"]',
      FIXED_CONTENT: '.fixed-top, .fixed-bottom, .is-fixed, .position-fixed'
      /**
       * ------------------------------------------------------------------------
       * Class Definition
       * ------------------------------------------------------------------------
       */

    };

    var Modal =
    /*#__PURE__*/
    function () {
      function Modal(element, config) {
        this._config = this._getConfig(config);
        this._element = element;
        this._dialog = element.querySelector(Selector.DIALOG);
        this._backdrop = null;
        this._isShown = false;
        this._isBodyOverflowing = false;
        this._ignoreBackdropClick = false;
        this._isTransitioning = false;
        this._scrollbarWidth = 0; // Boosted mod

        this._addAria(); // end mod

      } // Getters


      var _proto = Modal.prototype;

      // Public
      _proto.toggle = function toggle(relatedTarget) {
        return this._isShown ? this.hide() : this.show(relatedTarget);
      };

      _proto.show = function show(relatedTarget) {
        var _this = this;

        if (this._isShown || this._isTransitioning) {
          return;
        }

        if ($(this._element).hasClass(ClassName.FADE)) {
          this._isTransitioning = true;
        }

        var showEvent = $.Event(Event.SHOW, {
          relatedTarget: relatedTarget
        });
        $(this._element).trigger(showEvent);

        if (this._isShown || showEvent.isDefaultPrevented()) {
          return;
        }

        this._isShown = true;

        this._checkScrollbar();

        this._setScrollbar();

        this._setEscapeEvent();

        $(this._element).on(Event.CLICK_DISMISS, Selector.DATA_DISMISS, function (event) {
          return _this.hide(event);
        });
        $(this._dialog).on(Event.MOUSEDOWN_DISMISS, function () {
          $(_this._element).one(Event.MOUSEUP_DISMISS, function (event) {
            if ($(event.target).is(_this._element)) {
              _this._ignoreBackdropClick = true;
            }
          });
        });

        this._showBackdrop(function () {
          return _this._showElement(relatedTarget);
        });
      };

      _proto.hide = function hide(event) {
        var _this2 = this;

        if (event) {
          event.preventDefault();
        }

        if (!this._isShown || this._isTransitioning) {
          return;
        }

        var hideEvent = $.Event(Event.HIDE);
        $(this._element).trigger(hideEvent);

        if (!this._isShown || hideEvent.isDefaultPrevented()) {
          return;
        }

        this._isShown = false;
        var transition = $(this._element).hasClass(ClassName.FADE);

        if (transition) {
          this._isTransitioning = true;
        }

        this._setEscapeEvent();

        $(document).off(Event.FOCUSIN);
        $(this._element).removeClass(ClassName.SHOW);
        $(this._element).off(Event.CLICK_DISMISS);
        $(this._dialog).off(Event.MOUSEDOWN_DISMISS);

        if (transition) {
          var transitionDuration = Util.getTransitionDurationFromElement(this._element);
          $(this._element).one(Util.TRANSITION_END, function (event) {
            return _this2._hideModal(event);
          }).emulateTransitionEnd(transitionDuration);
        } else {
          this._hideModal();
        }
      };

      _proto.dispose = function dispose() {
        [window, this._element, this._dialog].forEach(function (htmlElement) {
          return $(htmlElement).off(EVENT_KEY);
        });
        /**
         * `document` has 2 events `Event.FOCUSIN` and `Event.CLICK_DATA_API`
         * Do not move `document` in `htmlElements` array
         * It will remove `Event.CLICK_DATA_API` event that should remain
         */

        $(document).off(Event.FOCUSIN);
        $.removeData(this._element, DATA_KEY);
        this._config = null;
        this._element = null;
        this._dialog = null;
        this._backdrop = null;
        this._isShown = null;
        this._isBodyOverflowing = null;
        this._ignoreBackdropClick = null;
        this._isTransitioning = null;
        this._scrollbarWidth = null;
      } // Private
      ;

      _proto._getConfig = function _getConfig(config) {
        config = _objectSpread({}, Default, config);
        Util.typeCheckConfig(NAME, config, DefaultType);
        return config;
      };

      _proto._showElement = function _showElement(relatedTarget) {
        var _this3 = this;

        var transition = $(this._element).hasClass(ClassName.FADE);

        if (!this._element.parentNode || this._element.parentNode.nodeType !== Node.ELEMENT_NODE) {
          // Don't move modal's DOM position
          document.body.appendChild(this._element);
        }

        this._element.style.display = 'block';

        this._element.removeAttribute('aria-hidden');

        this._element.setAttribute('aria-modal', true);

        if ($(this._dialog).hasClass(ClassName.SCROLLABLE)) {
          this._dialog.querySelector(Selector.MODAL_BODY).scrollTop = 0;
        } else {
          this._element.scrollTop = 0;
        }

        if (transition) {
          Util.reflow(this._element);
        }

        $(this._element).addClass(ClassName.SHOW);

        if (this._config.focus) {
          this._enforceFocus();
        }

        var shownEvent = $.Event(Event.SHOWN, {
          relatedTarget: relatedTarget
        });

        var transitionComplete = function transitionComplete() {
          if (_this3._config.focus) {
            _this3._element.focus();
          }

          _this3._isTransitioning = false;
          $(_this3._element).trigger(shownEvent);
        };

        if (transition) {
          var transitionDuration = Util.getTransitionDurationFromElement(this._dialog);
          $(this._dialog).one(Util.TRANSITION_END, transitionComplete).emulateTransitionEnd(transitionDuration);
        } else {
          transitionComplete();
        }
      };

      _proto._enforceFocus = function _enforceFocus() {
        var _this4 = this;

        $(document).off(Event.FOCUSIN) // Guard against infinite focus loop
        .on(Event.FOCUSIN, function (event) {
          if (document !== event.target && _this4._element !== event.target && $(_this4._element).has(event.target).length === 0) {
            _this4._element.focus();
          }
        });
      };

      _proto._setEscapeEvent = function _setEscapeEvent() {
        var _this5 = this;

        if (this._isShown && this._config.keyboard) {
          $(this._element).on(Event.KEYDOWN_DISMISS, function (event) {
            if (event.which === ESCAPE_KEYCODE) {
              event.preventDefault();

              _this5.hide();
            }
          });
        } else if (!this._isShown) {
          $(this._element).off(Event.KEYDOWN_DISMISS);
        }
      };

      _proto._hideModal = function _hideModal() {
        var _this6 = this;

        this._element.style.display = 'none';

        this._element.setAttribute('aria-hidden', true);

        this._element.removeAttribute('aria-modal');

        this._isTransitioning = false;

        this._showBackdrop(function () {
          $(document.body).removeClass(ClassName.OPEN);

          _this6._resetScrollbar();

          $(_this6._element).trigger(Event.HIDDEN);
        });
      };

      _proto._removeBackdrop = function _removeBackdrop() {
        if (this._backdrop) {
          $(this._backdrop).remove();
          this._backdrop = null;
        }
      };

      _proto._showBackdrop = function _showBackdrop(callback) {
        var _this7 = this;

        var animate = $(this._element).hasClass(ClassName.FADE) ? ClassName.FADE : '';

        if (this._isShown && this._config.backdrop) {
          this._backdrop = document.createElement('div');
          this._backdrop.className = ClassName.BACKDROP;

          if (animate) {
            this._backdrop.classList.add(animate);
          }

          $(this._backdrop).appendTo(document.body);
          $(this._element).on(Event.CLICK_DISMISS, function (event) {
            if (_this7._ignoreBackdropClick) {
              _this7._ignoreBackdropClick = false;
              return;
            }

            if (event.target !== event.currentTarget) {
              return;
            }

            if (_this7._config.backdrop === 'static') {
              _this7._element.focus();
            } else {
              _this7.hide();
            }
          });

          if (animate) {
            Util.reflow(this._backdrop);
          }

          $(this._backdrop).addClass(ClassName.SHOW);

          if (!callback) {
            return;
          }

          if (!animate) {
            callback();
            return;
          }

          var backdropTransitionDuration = Util.getTransitionDurationFromElement(this._backdrop);
          $(this._backdrop).one(Util.TRANSITION_END, callback).emulateTransitionEnd(backdropTransitionDuration);
        } else if (!this._isShown && this._backdrop) {
          $(this._backdrop).removeClass(ClassName.SHOW);

          var callbackRemove = function callbackRemove() {
            _this7._removeBackdrop();

            if (callback) {
              callback();
            }
          };

          if ($(this._element).hasClass(ClassName.FADE)) {
            var _backdropTransitionDuration = Util.getTransitionDurationFromElement(this._backdrop);

            $(this._backdrop).one(Util.TRANSITION_END, callbackRemove).emulateTransitionEnd(_backdropTransitionDuration);
          } else {
            callbackRemove();
          }
        } else if (callback) {
          callback();
        }
      } // ----------------------------------------------------------------------
      // the following methods are used to handle overflowing modals
      // todo (fat): these should probably be refactored out of modal.js
      // ----------------------------------------------------------------------
      ;

      _proto._checkScrollbar = function _checkScrollbar() {
        var rect = document.body.getBoundingClientRect();
        this._isBodyOverflowing = rect.left + rect.right < window.innerWidth;
        this._scrollbarWidth = this._getScrollbarWidth();
      };

      _proto._setScrollbar = function _setScrollbar() {
        var _this8 = this;

        if (this._isBodyOverflowing) {
          // Note: DOMNode.style.paddingRight returns the actual value or '' if not set
          //   while $(DOMNode).css('padding-right') returns the calculated value or 0 if not set
          var fixedContent = [].slice.call(document.querySelectorAll(Selector.FIXED_CONTENT)); // Adjust fixed content padding

          $(fixedContent).each(function (index, element) {
            var actualRight = element.style.right;
            var calculatedRight = $(element).css('right');
            $(element).data('right', actualRight).css('right', parseFloat(calculatedRight) + _this8._scrollbarWidth + "px");
          }); // Adjust body padding

          var actualPadding = document.body.style.paddingRight;
          var calculatedPadding = $(document.body).css('padding-right');
          $(document.body).data('padding-right', actualPadding).css('padding-right', parseFloat(calculatedPadding) + this._scrollbarWidth + "px");
        }

        $(document.body).addClass(ClassName.OPEN);
      };

      _proto._resetScrollbar = function _resetScrollbar() {
        // Restore fixed content padding
        var fixedContent = [].slice.call(document.querySelectorAll(Selector.FIXED_CONTENT));
        $(fixedContent).each(function (index, element) {
          var right = $(element).data('right');
          $(element).removeData('right');
          element.style.right = right ? right : '';
        }); // Restore body padding

        var padding = $(document.body).data('padding-right');
        $(document.body).removeData('padding-right');
        document.body.style.paddingRight = padding ? padding : '';
      };

      _proto._getScrollbarWidth = function _getScrollbarWidth() {
        // thx d.walsh
        var scrollDiv = document.createElement('div');
        scrollDiv.className = ClassName.SCROLLBAR_MEASURER;
        document.body.appendChild(scrollDiv);
        var scrollbarWidth = scrollDiv.getBoundingClientRect().width - scrollDiv.clientWidth;
        document.body.removeChild(scrollDiv);
        return scrollbarWidth;
      } // Boosted mod
      ;

      _proto._addAria = function _addAria() {
        var $ModalPanel = $(this._element);
        var $ModalTitle = $ModalPanel.find('.modal-title');
        var $ModalDialog = $ModalPanel.find('.modal-dialog');
        $ModalPanel.attr({
          role: 'dialog',
          'aria-modal': true
        });

        if ($ModalTitle) {
          var ModalTitleId = $ModalTitle.attr('id');

          if (ModalTitleId) {
            $ModalPanel.attr({
              'aria-labelledby': ModalTitleId
            });
          }
        }

        if ($ModalDialog) {
          $ModalDialog.attr('role', 'document');
        }
      } // end mod
      // Static
      ;

      Modal._jQueryInterface = function _jQueryInterface(config, relatedTarget) {
        return this.each(function () {
          var data = $(this).data(DATA_KEY);

          var _config = _objectSpread({}, Default, $(this).data(), typeof config === 'object' && config ? config : {});

          if (!data) {
            data = new Modal(this, _config);
            $(this).data(DATA_KEY, data);
          }

          if (typeof config === 'string') {
            if (typeof data[config] === 'undefined') {
              throw new TypeError("No method named \"" + config + "\"");
            }

            data[config](relatedTarget);
          } else if (_config.show) {
            data.show(relatedTarget);
          }
        });
      };

      _createClass(Modal, null, [{
        key: "VERSION",
        get: function get() {
          return VERSION;
        }
      }, {
        key: "Default",
        get: function get() {
          return Default;
        }
      }]);

      return Modal;
    }();
    /**
     * ------------------------------------------------------------------------
     * Data Api implementation
     * ------------------------------------------------------------------------
     */


    $(document).on(Event.CLICK_DATA_API, Selector.DATA_TOGGLE, function (event) {
      var _this9 = this;

      var target;
      var selector = Util.getSelectorFromElement(this);

      if (selector) {
        target = document.querySelector(selector);
      }

      var config = $(target).data(DATA_KEY) ? 'toggle' : _objectSpread({}, $(target).data(), $(this).data());

      if (this.tagName === 'A' || this.tagName === 'AREA') {
        event.preventDefault();
      }

      var $target = $(target).one(Event.SHOW, function (showEvent) {
        if (showEvent.isDefaultPrevented()) {
          // Only register focus restorer if modal will actually get shown
          return;
        }

        $target.one(Event.HIDDEN, function () {
          if ($(_this9).is(':visible')) {
            _this9.focus();
          }
        });
      });

      Modal._jQueryInterface.call($(target), config, this);
    });
    /**
     * ------------------------------------------------------------------------
     * jQuery
     * ------------------------------------------------------------------------
     */

    $.fn[NAME] = Modal._jQueryInterface;
    $.fn[NAME].Constructor = Modal;

    $.fn[NAME].noConflict = function () {
      $.fn[NAME] = JQUERY_NO_CONFLICT;
      return Modal._jQueryInterface;
    };

    return Modal;

  }));

  });

  var navbar = createCommonjsModule(function (module, exports) {
  /*!
    * Boosted v4.3.1 (https://boosted.orange.com)
    * Copyright 2014-2019 The Boosted Authors
    * Copyright 2014-2019 Orange
    * Licensed under MIT (https://github.com/orange-opensource/orange-boosted-bootstrap/blob/master/LICENSE)
    * This a fork of Bootstrap : Initial license below
    * Bootstrap navbar.js v4.3.1 (https://boosted.orange.com)
    * Copyright 2011-2019 The Boosted Authors (https://github.com/Orange-OpenSource/Orange-Boosted-Bootstrap/graphs/contributors)
    * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
    */
  (function (global, factory) {
     module.exports = factory(jquery, util) ;
  }(commonjsGlobal, function ($, Util) {
    $ = $ && $.hasOwnProperty('default') ? $['default'] : $;
    Util = Util && Util.hasOwnProperty('default') ? Util['default'] : Util;

    function _defineProperties(target, props) {
      for (var i = 0; i < props.length; i++) {
        var descriptor = props[i];
        descriptor.enumerable = descriptor.enumerable || false;
        descriptor.configurable = true;
        if ("value" in descriptor) descriptor.writable = true;
        Object.defineProperty(target, descriptor.key, descriptor);
      }
    }

    function _createClass(Constructor, protoProps, staticProps) {
      if (protoProps) _defineProperties(Constructor.prototype, protoProps);
      if (staticProps) _defineProperties(Constructor, staticProps);
      return Constructor;
    }

    function _defineProperty(obj, key, value) {
      if (key in obj) {
        Object.defineProperty(obj, key, {
          value: value,
          enumerable: true,
          configurable: true,
          writable: true
        });
      } else {
        obj[key] = value;
      }

      return obj;
    }

    function _objectSpread(target) {
      for (var i = 1; i < arguments.length; i++) {
        var source = arguments[i] != null ? arguments[i] : {};
        var ownKeys = Object.keys(source);

        if (typeof Object.getOwnPropertySymbols === 'function') {
          ownKeys = ownKeys.concat(Object.getOwnPropertySymbols(source).filter(function (sym) {
            return Object.getOwnPropertyDescriptor(source, sym).enumerable;
          }));
        }

        ownKeys.forEach(function (key) {
          _defineProperty(target, key, source[key]);
        });
      }

      return target;
    }

    /**
     * ------------------------------------------------------------------------
     * Constants
     * ------------------------------------------------------------------------
     */

    var NAME = 'navbar';
    var VERSION = '4.3.1';
    var DATA_KEY = 'bs.navbar';
    var JQUERY_NO_CONFLICT = $.fn[NAME];
    var BREAKPOINT = 768;
    var Default = {
      sticky: false,
      trigger: ''
    };
    var DefaultType = {
      sticky: 'boolean',
      trigger: 'string'
    };
    var Selector = {
      SUPRA_BAR: '.navbar.supra',
      MEGAMENU_PANEL: '.mega-menu.panel'
      /**
       * ------------------------------------------------------------------------
       * Class Definition
       * ------------------------------------------------------------------------
       */

    };

    var Navbar =
    /*#__PURE__*/
    function () {
      function Navbar(element, config) {
        var _this = this;

        this._element = element;
        this._supraBar = element.querySelector(Selector.SUPRA_BAR);
        this._config = this._getConfig(config);
        this._initialHeight = $(this._element).outerHeight();
        this._initialSupraHeight = $(this._supraBar).outerHeight();

        this._addAria();

        if (this._config.sticky) {
          $(this._element).addClass('fixed-top');
          $(Selector.MEGAMENU_PANEL).addClass('sticky');
          $(document.body).css('padding-top', this._initialHeight);
          $(window).on('scroll', function () {
            var Scroll = $(window).scrollTop();

            if (Scroll > 0) {
              $(_this._element).addClass('minimized');
            } else {
              $(_this._element).removeClass('minimized');
            }
          });
        }

        if (this._config.hideSupra) {
          $(window).on('scroll', function () {
            if ($(window).innerWidth() < BREAKPOINT) {
              return;
            }

            var Scroll = $(window).scrollTop();

            if (Scroll > 0) {
              $(Selector.SUPRA_BAR).hide();
            } else {
              $(Selector.SUPRA_BAR).show();
            }
          });
        }
      } // getters


      var _proto = Navbar.prototype;

      // private
      _proto._getConfig = function _getConfig(config) {
        config = $.extend({}, Default, config);
        Util.typeCheckConfig(NAME, config, DefaultType);
        return config;
      };

      _proto._addAria = function _addAria() {
        $(this._element).find('.navbar .nav-link[data-toggle]').attr('aria-haspopup', true);
      } // static
      ;

      Navbar._jQueryInterface = function _jQueryInterface(config) {
        return this.each(function () {
          var data = $(this).data(DATA_KEY);

          var _config = _objectSpread({}, Default, $(this).data(), typeof config === 'object' && config ? config : {});

          if (!data) {
            data = new Navbar(this, _config);
            $(this).data(DATA_KEY, data);
          }

          if (typeof config === 'string') {
            if (typeof data[config] === 'undefined') {
              throw new TypeError("No method named \"" + config + "\"");
            }

            data[config]();
          }
        });
      };

      _createClass(Navbar, null, [{
        key: "VERSION",
        get: function get() {
          return VERSION;
        }
      }, {
        key: "Default",
        get: function get() {
          return Default;
        }
      }]);

      return Navbar;
    }();
    /**
     * ------------------------------------------------------------------------
     * jQuery
     * ------------------------------------------------------------------------
     */


    $.fn[NAME] = Navbar._jQueryInterface;
    $.fn[NAME].Constructor = Navbar;

    $.fn[NAME].noConflict = function () {
      $.fn[NAME] = JQUERY_NO_CONFLICT;
      return Navbar._jQueryInterface;
    };

    return Navbar;

  }));

  });

  var otab = createCommonjsModule(function (module, exports) {
  /*!
    * Boosted v4.3.1 (https://boosted.orange.com)
    * Copyright 2014-2019 The Boosted Authors
    * Copyright 2014-2019 Orange
    * Licensed under MIT (https://github.com/orange-opensource/orange-boosted-bootstrap/blob/master/LICENSE)
    * This a fork of Bootstrap : Initial license below
    * Bootstrap otab.js v4.3.1 (https://boosted.orange.com)
    * Copyright 2011-2019 The Boosted Authors (https://github.com/Orange-OpenSource/Orange-Boosted-Bootstrap/graphs/contributors)
    * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
    */
  (function (global, factory) {
     module.exports = factory(jquery, util) ;
  }(commonjsGlobal, function ($, Util) {
    $ = $ && $.hasOwnProperty('default') ? $['default'] : $;
    Util = Util && Util.hasOwnProperty('default') ? Util['default'] : Util;

    function _defineProperties(target, props) {
      for (var i = 0; i < props.length; i++) {
        var descriptor = props[i];
        descriptor.enumerable = descriptor.enumerable || false;
        descriptor.configurable = true;
        if ("value" in descriptor) descriptor.writable = true;
        Object.defineProperty(target, descriptor.key, descriptor);
      }
    }

    function _createClass(Constructor, protoProps, staticProps) {
      if (protoProps) _defineProperties(Constructor.prototype, protoProps);
      if (staticProps) _defineProperties(Constructor, staticProps);
      return Constructor;
    }

    /**
     * ------------------------------------------------------------------------
     * Constants
     * ------------------------------------------------------------------------
     */

    var NAME = 'otab';
    var VERSION = '4.3.1';
    var DATA_KEY = 'bs.otab';
    var EVENT_KEY = "." + DATA_KEY;
    var DATA_API_KEY = '.data-api';
    var JQUERY_NO_CONFLICT = $.fn[NAME];
    var DEFAULT_THRESHOLD = 2;
    var Event = {
      CLICK_DATA_API: "click" + EVENT_KEY + DATA_API_KEY
    };
    var ClassName = {
      ACTIVE: 'active',
      SHOW: 'show',
      ACCORDION_LAYOUT: 'accordion-layout'
    };
    var Selector = {
      OTAB_HEADING: '.o-tab-heading',
      OTAB_CONTENT: '.o-tab-content'
      /**
       * ------------------------------------------------------------------------
       * Class Definition
       * ------------------------------------------------------------------------
       */

    };

    var Otab =
    /*#__PURE__*/
    function () {
      function Otab(element) {
        this._element = element;

        this._addAccessibility();

        if ($(this._element).parent().find(Selector.OTAB_HEADING).length > DEFAULT_THRESHOLD) {
          $(this._element).parent().addClass(ClassName.ACCORDION_LAYOUT);
        }
      } // getters


      var _proto = Otab.prototype;

      // public
      _proto.show = function show() {
        var $element = $(this._element);

        if ($element.next().hasClass(ClassName.SHOW)) {
          return;
        } // from parent remove all tab-content show classes


        $element.parent().find(Selector.OTAB_CONTENT).removeClass(ClassName.SHOW); // remove all aria-expanded=true

        $element.parent().find('[aria-expanded="true"]').attr('aria-expanded', false); // add show class to next tab-content

        $element.next().addClass(ClassName.SHOW); // add aria-expanded=true to element

        $element.attr('aria-expanded', true);
      } // private
      ;

      _proto._addAccessibility = function _addAccessibility() {
        var $tab = $(this._element);
        var $tabpanel = $tab.next();
        $tab.attr('id', Util.getUID(NAME));
        $tabpanel.attr('id', Util.getUID(NAME));
        $tab.attr({
          'aria-controls': $tabpanel.attr('id'),
          role: 'tab'
        });
        $tabpanel.attr({
          'aria-labelledby': $tab.attr('id'),
          role: 'tabpanel',
          tabindex: 0
        });

        if ($tabpanel.hasClass(ClassName.SHOW)) {
          $tab.attr('aria-expanded', true);
        } else {
          $tab.attr('aria-expanded', false);
        }
      } // static
      ;

      Otab._jQueryInterface = function _jQueryInterface(config) {
        return this.each(function () {
          var $this = $(this);
          var data = $this.data(DATA_KEY);

          if (!data) {
            data = new Otab(this);
            $this.data(DATA_KEY, data);
          } // Boosted mod


          if (/init/.test(config)) {
            return;
          } // end mod


          if (typeof config === 'string') {
            if (typeof data[config] === 'undefined') {
              throw new TypeError("No method named \"" + config + "\"");
            }

            data[config]();
          }
        });
      };

      _createClass(Otab, null, [{
        key: "VERSION",
        get: function get() {
          return VERSION;
        }
      }]);

      return Otab;
    }();
    /**
     * ------------------------------------------------------------------------
     * Data Api implementation
     * ------------------------------------------------------------------------
     */


    $(document).on('DOMContentLoaded', function () {
      Otab._jQueryInterface.call($(Selector.OTAB_HEADING), 'init');
    }).on(Event.CLICK_DATA_API, Selector.OTAB_HEADING, function (event) {
      event.preventDefault();

      Otab._jQueryInterface.call($(this), ClassName.SHOW);
    });
    /**
     * ------------------------------------------------------------------------
     * jQuery
     * ------------------------------------------------------------------------
     */

    $.fn[NAME] = Otab._jQueryInterface;
    $.fn[NAME].Constructor = Otab;

    $.fn[NAME].noConflict = function () {
      $.fn[NAME] = JQUERY_NO_CONFLICT;
      return Otab._jQueryInterface;
    };

    return Otab;

  }));

  });

  var tooltip = createCommonjsModule(function (module, exports) {
  /*!
    * Boosted v4.3.1 (https://boosted.orange.com)
    * Copyright 2014-2019 The Boosted Authors
    * Copyright 2014-2019 Orange
    * Licensed under MIT (https://github.com/orange-opensource/orange-boosted-bootstrap/blob/master/LICENSE)
    * This a fork of Bootstrap : Initial license below
    * Bootstrap tooltip.js v4.3.1 (https://boosted.orange.com)
    * Copyright 2011-2019 The Boosted Authors (https://github.com/Orange-OpenSource/Orange-Boosted-Bootstrap/graphs/contributors)
    * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
    */
  (function (global, factory) {
     module.exports = factory(jquery, popper, util) ;
  }(commonjsGlobal, function ($, Popper, Util) {
    $ = $ && $.hasOwnProperty('default') ? $['default'] : $;
    Popper = Popper && Popper.hasOwnProperty('default') ? Popper['default'] : Popper;
    Util = Util && Util.hasOwnProperty('default') ? Util['default'] : Util;

    function _defineProperties(target, props) {
      for (var i = 0; i < props.length; i++) {
        var descriptor = props[i];
        descriptor.enumerable = descriptor.enumerable || false;
        descriptor.configurable = true;
        if ("value" in descriptor) descriptor.writable = true;
        Object.defineProperty(target, descriptor.key, descriptor);
      }
    }

    function _createClass(Constructor, protoProps, staticProps) {
      if (protoProps) _defineProperties(Constructor.prototype, protoProps);
      if (staticProps) _defineProperties(Constructor, staticProps);
      return Constructor;
    }

    function _defineProperty(obj, key, value) {
      if (key in obj) {
        Object.defineProperty(obj, key, {
          value: value,
          enumerable: true,
          configurable: true,
          writable: true
        });
      } else {
        obj[key] = value;
      }

      return obj;
    }

    function _objectSpread(target) {
      for (var i = 1; i < arguments.length; i++) {
        var source = arguments[i] != null ? arguments[i] : {};
        var ownKeys = Object.keys(source);

        if (typeof Object.getOwnPropertySymbols === 'function') {
          ownKeys = ownKeys.concat(Object.getOwnPropertySymbols(source).filter(function (sym) {
            return Object.getOwnPropertyDescriptor(source, sym).enumerable;
          }));
        }

        ownKeys.forEach(function (key) {
          _defineProperty(target, key, source[key]);
        });
      }

      return target;
    }

    /**
     * --------------------------------------------------------------------------
     * Bootstrap (v4.3.1): tools/sanitizer.js
     * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
     * --------------------------------------------------------------------------
     */
    var uriAttrs = ['background', 'cite', 'href', 'itemtype', 'longdesc', 'poster', 'src', 'xlink:href'];
    var ARIA_ATTRIBUTE_PATTERN = /^aria-[\w-]*$/i;
    var DefaultWhitelist = {
      // Global attributes allowed on any supplied element below.
      '*': ['class', 'dir', 'id', 'lang', 'role', ARIA_ATTRIBUTE_PATTERN],
      a: ['target', 'href', 'title', 'rel'],
      area: [],
      b: [],
      br: [],
      col: [],
      code: [],
      div: [],
      em: [],
      hr: [],
      h1: [],
      h2: [],
      h3: [],
      h4: [],
      h5: [],
      h6: [],
      i: [],
      img: ['src', 'alt', 'title', 'width', 'height'],
      li: [],
      ol: [],
      p: [],
      pre: [],
      s: [],
      small: [],
      span: [],
      sub: [],
      sup: [],
      strong: [],
      u: [],
      ul: []
      /**
       * A pattern that recognizes a commonly useful subset of URLs that are safe.
       *
       * Shoutout to Angular 7 https://github.com/angular/angular/blob/7.2.4/packages/core/src/sanitization/url_sanitizer.ts
       */

    };
    var SAFE_URL_PATTERN = /^(?:(?:https?|mailto|ftp|tel|file):|[^&:/?#]*(?:[/?#]|$))/gi;
    /**
     * A pattern that matches safe data URLs. Only matches image, video and audio types.
     *
     * Shoutout to Angular 7 https://github.com/angular/angular/blob/7.2.4/packages/core/src/sanitization/url_sanitizer.ts
     */

    var DATA_URL_PATTERN = /^data:(?:image\/(?:bmp|gif|jpeg|jpg|png|tiff|webp)|video\/(?:mpeg|mp4|ogg|webm)|audio\/(?:mp3|oga|ogg|opus));base64,[a-z0-9+/]+=*$/i;

    function allowedAttribute(attr, allowedAttributeList) {
      var attrName = attr.nodeName.toLowerCase();

      if (allowedAttributeList.indexOf(attrName) !== -1) {
        if (uriAttrs.indexOf(attrName) !== -1) {
          return Boolean(attr.nodeValue.match(SAFE_URL_PATTERN) || attr.nodeValue.match(DATA_URL_PATTERN));
        }

        return true;
      }

      var regExp = allowedAttributeList.filter(function (attrRegex) {
        return attrRegex instanceof RegExp;
      }); // Check if a regular expression validates the attribute.

      for (var i = 0, l = regExp.length; i < l; i++) {
        if (attrName.match(regExp[i])) {
          return true;
        }
      }

      return false;
    }

    function sanitizeHtml(unsafeHtml, whiteList, sanitizeFn) {
      if (unsafeHtml.length === 0) {
        return unsafeHtml;
      }

      if (sanitizeFn && typeof sanitizeFn === 'function') {
        return sanitizeFn(unsafeHtml);
      }

      var domParser = new window.DOMParser();
      var createdDocument = domParser.parseFromString(unsafeHtml, 'text/html');
      var whitelistKeys = Object.keys(whiteList);
      var elements = [].slice.call(createdDocument.body.querySelectorAll('*'));

      var _loop = function _loop(i, len) {
        var el = elements[i];
        var elName = el.nodeName.toLowerCase();

        if (whitelistKeys.indexOf(el.nodeName.toLowerCase()) === -1) {
          el.parentNode.removeChild(el);
          return "continue";
        }

        var attributeList = [].slice.call(el.attributes);
        var whitelistedAttributes = [].concat(whiteList['*'] || [], whiteList[elName] || []);
        attributeList.forEach(function (attr) {
          if (!allowedAttribute(attr, whitelistedAttributes)) {
            el.removeAttribute(attr.nodeName);
          }
        });
      };

      for (var i = 0, len = elements.length; i < len; i++) {
        var _ret = _loop(i);

        if (_ret === "continue") continue;
      }

      return createdDocument.body.innerHTML;
    }

    /**
     * ------------------------------------------------------------------------
     * Constants
     * ------------------------------------------------------------------------
     */

    var NAME = 'tooltip';
    var VERSION = '4.3.1';
    var DATA_KEY = 'bs.tooltip';
    var EVENT_KEY = "." + DATA_KEY;
    var JQUERY_NO_CONFLICT = $.fn[NAME];
    var CLASS_PREFIX = 'bs-tooltip';
    var BSCLS_PREFIX_REGEX = new RegExp("(^|\\s)" + CLASS_PREFIX + "\\S+", 'g');
    var DISALLOWED_ATTRIBUTES = ['sanitize', 'whiteList', 'sanitizeFn'];
    var DefaultType = {
      animation: 'boolean',
      template: 'string',
      title: '(string|element|function)',
      trigger: 'string',
      delay: '(number|object)',
      html: 'boolean',
      selector: '(string|boolean)',
      placement: '(string|function)',
      offset: '(number|string|function)',
      container: '(string|element|boolean)',
      fallbackPlacement: '(string|array)',
      boundary: '(string|element)',
      sanitize: 'boolean',
      sanitizeFn: '(null|function)',
      whiteList: 'object'
    };
    var AttachmentMap = {
      AUTO: 'auto',
      TOP: 'top',
      RIGHT: 'right',
      BOTTOM: 'bottom',
      LEFT: 'left'
    };
    var Default = {
      animation: true,
      template: '<div class="tooltip" role="tooltip">' + '<div class="arrow"></div>' + '<div class="tooltip-inner"></div></div>',
      trigger: 'hover focus',
      title: '',
      delay: 0,
      html: false,
      selector: false,
      placement: 'top',
      offset: 0,
      container: false,
      fallbackPlacement: 'flip',
      boundary: 'scrollParent',
      sanitize: true,
      sanitizeFn: null,
      whiteList: DefaultWhitelist
    };
    var HoverState = {
      SHOW: 'show',
      OUT: 'out'
    };
    var Event = {
      HIDE: "hide" + EVENT_KEY,
      HIDDEN: "hidden" + EVENT_KEY,
      SHOW: "show" + EVENT_KEY,
      SHOWN: "shown" + EVENT_KEY,
      INSERTED: "inserted" + EVENT_KEY,
      CLICK: "click" + EVENT_KEY,
      FOCUSIN: "focusin" + EVENT_KEY,
      FOCUSOUT: "focusout" + EVENT_KEY,
      MOUSEENTER: "mouseenter" + EVENT_KEY,
      MOUSELEAVE: "mouseleave" + EVENT_KEY
    };
    var ClassName = {
      FADE: 'fade',
      SHOW: 'show'
    };
    var Selector = {
      TOOLTIP: '.tooltip',
      TOOLTIP_INNER: '.tooltip-inner',
      ARROW: '.arrow'
    };
    var Trigger = {
      HOVER: 'hover',
      FOCUS: 'focus',
      CLICK: 'click',
      MANUAL: 'manual'
      /**
       * ------------------------------------------------------------------------
       * Class Definition
       * ------------------------------------------------------------------------
       */

    };

    var Tooltip =
    /*#__PURE__*/
    function () {
      function Tooltip(element, config) {
        /**
         * Check for Popper dependency
         * Popper - https://popper.js.org
         */
        if (typeof Popper === 'undefined') {
          throw new TypeError('Bootstrap\'s tooltips require Popper.js (https://popper.js.org/)');
        } // private


        this._isEnabled = true;
        this._timeout = 0;
        this._hoverState = '';
        this._activeTrigger = {};
        this._popper = null; // Protected

        this.element = element;
        this.config = this._getConfig(config);
        this.tip = null;

        this._setListeners();
      } // Getters


      var _proto = Tooltip.prototype;

      // Public
      _proto.enable = function enable() {
        this._isEnabled = true;
      };

      _proto.disable = function disable() {
        this._isEnabled = false;
      };

      _proto.toggleEnabled = function toggleEnabled() {
        this._isEnabled = !this._isEnabled;
      };

      _proto.toggle = function toggle(event) {
        if (!this._isEnabled) {
          return;
        }

        if (event) {
          var dataKey = this.constructor.DATA_KEY;
          var context = $(event.currentTarget).data(dataKey);

          if (!context) {
            context = new this.constructor(event.currentTarget, this._getDelegateConfig());
            $(event.currentTarget).data(dataKey, context);
          }

          context._activeTrigger.click = !context._activeTrigger.click;

          if (context._isWithActiveTrigger()) {
            context._enter(null, context);
          } else {
            context._leave(null, context);
          }
        } else {
          if ($(this.getTipElement()).hasClass(ClassName.SHOW)) {
            this._leave(null, this);

            return;
          }

          this._enter(null, this);
        }
      };

      _proto.dispose = function dispose() {
        clearTimeout(this._timeout);
        $.removeData(this.element, this.constructor.DATA_KEY);
        $(this.element).off(this.constructor.EVENT_KEY);
        $(this.element).closest('.modal').off('hide.bs.modal');

        if (this.tip) {
          $(this.tip).remove();
        }

        this._isEnabled = null;
        this._timeout = null;
        this._hoverState = null;
        this._activeTrigger = null;

        if (this._popper !== null) {
          this._popper.destroy();
        }

        this._popper = null;
        this.element = null;
        this.config = null;
        this.tip = null;
      };

      _proto.show = function show() {
        var _this = this;

        if ($(this.element).css('display') === 'none') {
          throw new Error('Please use show on visible elements');
        }

        var showEvent = $.Event(this.constructor.Event.SHOW);

        if (this.isWithContent() && this._isEnabled) {
          $(this.element).trigger(showEvent);
          var shadowRoot = Util.findShadowRoot(this.element);
          var isInTheDom = $.contains(shadowRoot !== null ? shadowRoot : this.element.ownerDocument.documentElement, this.element);

          if (showEvent.isDefaultPrevented() || !isInTheDom) {
            return;
          }

          var tip = this.getTipElement();
          var tipId = Util.getUID(this.constructor.NAME);
          tip.setAttribute('id', tipId);
          this.element.setAttribute('aria-describedby', tipId);
          this.setContent();

          if (this.config.animation) {
            $(tip).addClass(ClassName.FADE);
          }

          var placement = typeof this.config.placement === 'function' ? this.config.placement.call(this, tip, this.element) : this.config.placement; // boosted mod fix rtl

          var attachment = this._getAttachment(placement);

          this.addAttachmentClass(attachment);

          var container = this._getContainer();

          $(tip).data(this.constructor.DATA_KEY, this);

          if (!$.contains(this.element.ownerDocument.documentElement, this.tip)) {
            $(tip).appendTo(container);
          }

          $(this.element).trigger(this.constructor.Event.INSERTED); // boosted mod fix rtl

          var dir = document.getElementsByTagName('html')[0].dir;

          if (dir === 'rtl') {
            var hash = {
              right: 'left',
              left: 'right'
            };
            attachment = attachment.replace(/right|left/g, function (matched) {
              return hash[matched];
            });
          } // end mod


          this._popper = new Popper(this.element, tip, {
            placement: attachment,
            modifiers: {
              offset: this._getOffset(),
              flip: {
                behavior: this.config.fallbackPlacement
              },
              arrow: {
                element: Selector.ARROW
              },
              preventOverflow: {
                boundariesElement: this.config.boundary
              }
            },
            onCreate: function onCreate(data) {
              if (data.originalPlacement !== data.placement) {
                _this._handlePopperPlacementChange(data);
              }
            },
            onUpdate: function onUpdate(data) {
              return _this._handlePopperPlacementChange(data);
            }
          });
          $(tip).addClass(ClassName.SHOW); // If this is a touch-enabled device we add extra
          // empty mouseover listeners to the body's immediate children;
          // only needed because of broken event delegation on iOS
          // https://www.quirksmode.org/blog/archives/2014/02/mouse_event_bub.html

          if ('ontouchstart' in document.documentElement) {
            $(document.body).children().on('mouseover', null, $.noop);
          }

          var complete = function complete() {
            if (_this.config.animation) {
              _this._fixTransition();
            }

            var prevHoverState = _this._hoverState;
            _this._hoverState = null;
            $(_this.element).trigger(_this.constructor.Event.SHOWN);

            if (prevHoverState === HoverState.OUT) {
              _this._leave(null, _this);
            }
          };

          if ($(this.tip).hasClass(ClassName.FADE)) {
            var transitionDuration = Util.getTransitionDurationFromElement(this.tip);
            $(this.tip).one(Util.TRANSITION_END, complete).emulateTransitionEnd(transitionDuration);
          } else {
            complete();
          }
        }
      };

      _proto.hide = function hide(callback) {
        var _this2 = this;

        var tip = this.getTipElement();
        var hideEvent = $.Event(this.constructor.Event.HIDE);

        var complete = function complete() {
          if (_this2._hoverState !== HoverState.SHOW && tip.parentNode) {
            tip.parentNode.removeChild(tip);
          }

          _this2._cleanTipClass();

          _this2.element.removeAttribute('aria-describedby');

          $(_this2.element).trigger(_this2.constructor.Event.HIDDEN);

          if (_this2._popper !== null) {
            _this2._popper.destroy();
          }

          if (callback) {
            callback();
          }
        };

        $(this.element).trigger(hideEvent);

        if (hideEvent.isDefaultPrevented()) {
          return;
        }

        $(tip).removeClass(ClassName.SHOW); // If this is a touch-enabled device we remove the extra
        // empty mouseover listeners we added for iOS support

        if ('ontouchstart' in document.documentElement) {
          $(document.body).children().off('mouseover', null, $.noop);
        }

        this._activeTrigger[Trigger.CLICK] = false;
        this._activeTrigger[Trigger.FOCUS] = false;
        this._activeTrigger[Trigger.HOVER] = false;

        if ($(this.tip).hasClass(ClassName.FADE)) {
          var transitionDuration = Util.getTransitionDurationFromElement(tip);
          $(tip).one(Util.TRANSITION_END, complete).emulateTransitionEnd(transitionDuration);
        } else {
          complete();
        }

        this._hoverState = '';
      };

      _proto.update = function update() {
        if (this._popper !== null) {
          this._popper.scheduleUpdate();
        }
      } // Protected
      ;

      _proto.isWithContent = function isWithContent() {
        return Boolean(this.getTitle());
      };

      _proto.addAttachmentClass = function addAttachmentClass(attachment) {
        $(this.getTipElement()).addClass(CLASS_PREFIX + "-" + attachment);
      };

      _proto.getTipElement = function getTipElement() {
        this.tip = this.tip || $(this.config.template)[0];
        return this.tip;
      };

      _proto.setContent = function setContent() {
        var tip = this.getTipElement();
        this.setElementContent($(tip.querySelectorAll(Selector.TOOLTIP_INNER)), this.getTitle());
        $(tip).removeClass(ClassName.FADE + " " + ClassName.SHOW);
      };

      _proto.setElementContent = function setElementContent($element, content) {
        if (typeof content === 'object' && (content.nodeType || content.jquery)) {
          // Content is a DOM node or a jQuery
          if (this.config.html) {
            if (!$(content).parent().is($element)) {
              $element.empty().append(content);
            }
          } else {
            $element.text($(content).text());
          }

          return;
        }

        if (this.config.html) {
          if (this.config.sanitize) {
            content = sanitizeHtml(content, this.config.whiteList, this.config.sanitizeFn);
          }

          $element.html(content);
        } else {
          $element.text(content);
        }
      };

      _proto.getTitle = function getTitle() {
        var title = this.element.getAttribute('data-original-title');

        if (!title) {
          title = typeof this.config.title === 'function' ? this.config.title.call(this.element) : this.config.title;
        }

        return title;
      } // Private
      ;

      _proto._getOffset = function _getOffset() {
        var _this3 = this;

        var offset = {};

        if (typeof this.config.offset === 'function') {
          offset.fn = function (data) {
            data.offsets = _objectSpread({}, data.offsets, _this3.config.offset(data.offsets, _this3.element) || {});
            return data;
          };
        } else {
          offset.offset = this.config.offset;
        }

        return offset;
      };

      _proto._getContainer = function _getContainer() {
        if (this.config.container === false) {
          return document.body;
        }

        if (Util.isElement(this.config.container)) {
          return $(this.config.container);
        }

        return $(document).find(this.config.container);
      };

      _proto._getAttachment = function _getAttachment(placement) {
        return AttachmentMap[placement.toUpperCase()];
      };

      _proto._setListeners = function _setListeners() {
        var _this4 = this;

        var triggers = this.config.trigger.split(' ');
        triggers.forEach(function (trigger) {
          if (trigger === 'click') {
            $(_this4.element).on(_this4.constructor.Event.CLICK, _this4.config.selector, function (event) {
              return _this4.toggle(event);
            });
          } else if (trigger !== Trigger.MANUAL) {
            var eventIn = trigger === Trigger.HOVER ? _this4.constructor.Event.MOUSEENTER : _this4.constructor.Event.FOCUSIN;
            var eventOut = trigger === Trigger.HOVER ? _this4.constructor.Event.MOUSELEAVE : _this4.constructor.Event.FOCUSOUT;
            $(_this4.element).on(eventIn, _this4.config.selector, function (event) {
              return _this4._enter(event);
            }).on(eventOut, _this4.config.selector, function (event) {
              return _this4._leave(event);
            });
          }
        });
        $(this.element).closest('.modal').on('hide.bs.modal', function () {
          if (_this4.element) {
            _this4.hide();
          }
        });

        if (this.config.selector) {
          this.config = _objectSpread({}, this.config, {
            trigger: 'manual',
            selector: ''
          });
        } else {
          this._fixTitle();
        }
      };

      _proto._fixTitle = function _fixTitle() {
        var titleType = typeof this.element.getAttribute('data-original-title');

        if (this.element.getAttribute('title') || titleType !== 'string') {
          this.element.setAttribute('data-original-title', this.element.getAttribute('title') || '');
          this.element.setAttribute('title', '');
        }
      };

      _proto._enter = function _enter(event, context) {
        var dataKey = this.constructor.DATA_KEY;
        context = context || $(event.currentTarget).data(dataKey);

        if (!context) {
          context = new this.constructor(event.currentTarget, this._getDelegateConfig());
          $(event.currentTarget).data(dataKey, context);
        }

        if (event) {
          context._activeTrigger[event.type === 'focusin' ? Trigger.FOCUS : Trigger.HOVER] = true;
        }

        if ($(context.getTipElement()).hasClass(ClassName.SHOW) || context._hoverState === HoverState.SHOW) {
          context._hoverState = HoverState.SHOW;
          return;
        }

        clearTimeout(context._timeout);
        context._hoverState = HoverState.SHOW;

        if (!context.config.delay || !context.config.delay.show) {
          context.show();
          return;
        }

        context._timeout = setTimeout(function () {
          if (context._hoverState === HoverState.SHOW) {
            context.show();
          }
        }, context.config.delay.show);
      };

      _proto._leave = function _leave(event, context) {
        var dataKey = this.constructor.DATA_KEY;
        context = context || $(event.currentTarget).data(dataKey);

        if (!context) {
          context = new this.constructor(event.currentTarget, this._getDelegateConfig());
          $(event.currentTarget).data(dataKey, context);
        }

        if (event) {
          context._activeTrigger[event.type === 'focusout' ? Trigger.FOCUS : Trigger.HOVER] = false;
        }

        if (context._isWithActiveTrigger()) {
          return;
        }

        clearTimeout(context._timeout);
        context._hoverState = HoverState.OUT;

        if (!context.config.delay || !context.config.delay.hide) {
          context.hide();
          return;
        }

        context._timeout = setTimeout(function () {
          if (context._hoverState === HoverState.OUT) {
            context.hide();
          }
        }, context.config.delay.hide);
      };

      _proto._isWithActiveTrigger = function _isWithActiveTrigger() {
        for (var trigger in this._activeTrigger) {
          if (this._activeTrigger[trigger]) {
            return true;
          }
        }

        return false;
      };

      _proto._getConfig = function _getConfig(config) {
        var dataAttributes = $(this.element).data();
        Object.keys(dataAttributes).forEach(function (dataAttr) {
          if (DISALLOWED_ATTRIBUTES.indexOf(dataAttr) !== -1) {
            delete dataAttributes[dataAttr];
          }
        });
        config = _objectSpread({}, this.constructor.Default, dataAttributes, typeof config === 'object' && config ? config : {});

        if (typeof config.delay === 'number') {
          config.delay = {
            show: config.delay,
            hide: config.delay
          };
        }

        if (typeof config.title === 'number') {
          config.title = config.title.toString();
        }

        if (typeof config.content === 'number') {
          config.content = config.content.toString();
        }

        Util.typeCheckConfig(NAME, config, this.constructor.DefaultType);

        if (config.sanitize) {
          config.template = sanitizeHtml(config.template, config.whiteList, config.sanitizeFn);
        }

        return config;
      };

      _proto._getDelegateConfig = function _getDelegateConfig() {
        var config = {};

        if (this.config) {
          for (var key in this.config) {
            if (this.constructor.Default[key] !== this.config[key]) {
              config[key] = this.config[key];
            }
          }
        }

        return config;
      };

      _proto._cleanTipClass = function _cleanTipClass() {
        var $tip = $(this.getTipElement());
        var tabClass = $tip.attr('class').match(BSCLS_PREFIX_REGEX);

        if (tabClass !== null && tabClass.length) {
          $tip.removeClass(tabClass.join(''));
        }
      };

      _proto._handlePopperPlacementChange = function _handlePopperPlacementChange(popperData) {
        var popperInstance = popperData.instance;
        this.tip = popperInstance.popper;

        this._cleanTipClass();

        this.addAttachmentClass(this._getAttachment(popperData.placement));
      };

      _proto._fixTransition = function _fixTransition() {
        var tip = this.getTipElement();
        var initConfigAnimation = this.config.animation;

        if (tip.getAttribute('x-placement') !== null) {
          return;
        }

        $(tip).removeClass(ClassName.FADE);
        this.config.animation = false;
        this.hide();
        this.show();
        this.config.animation = initConfigAnimation;
      } // Static
      ;

      Tooltip._jQueryInterface = function _jQueryInterface(config) {
        return this.each(function () {
          var data = $(this).data(DATA_KEY);

          var _config = typeof config === 'object' && config;

          if (!data && /dispose|hide/.test(config)) {
            return;
          }

          if (!data) {
            data = new Tooltip(this, _config);
            $(this).data(DATA_KEY, data);
          }

          if (typeof config === 'string') {
            if (typeof data[config] === 'undefined') {
              throw new TypeError("No method named \"" + config + "\"");
            }

            data[config]();
          }
        });
      };

      _createClass(Tooltip, null, [{
        key: "VERSION",
        get: function get() {
          return VERSION;
        }
      }, {
        key: "Default",
        get: function get() {
          return Default;
        }
      }, {
        key: "NAME",
        get: function get() {
          return NAME;
        }
      }, {
        key: "DATA_KEY",
        get: function get() {
          return DATA_KEY;
        }
      }, {
        key: "Event",
        get: function get() {
          return Event;
        }
      }, {
        key: "EVENT_KEY",
        get: function get() {
          return EVENT_KEY;
        }
      }, {
        key: "DefaultType",
        get: function get() {
          return DefaultType;
        }
      }]);

      return Tooltip;
    }();
    /**
     * ------------------------------------------------------------------------
     * jQuery
     * ------------------------------------------------------------------------
     */


    $.fn[NAME] = Tooltip._jQueryInterface;
    $.fn[NAME].Constructor = Tooltip;

    $.fn[NAME].noConflict = function () {
      $.fn[NAME] = JQUERY_NO_CONFLICT;
      return Tooltip._jQueryInterface;
    };

    return Tooltip;

  }));

  });

  var popover = createCommonjsModule(function (module, exports) {
  /*!
    * Boosted v4.3.1 (https://boosted.orange.com)
    * Copyright 2014-2019 The Boosted Authors
    * Copyright 2014-2019 Orange
    * Licensed under MIT (https://github.com/orange-opensource/orange-boosted-bootstrap/blob/master/LICENSE)
    * This a fork of Bootstrap : Initial license below
    * Bootstrap popover.js v4.3.1 (https://boosted.orange.com)
    * Copyright 2011-2019 The Boosted Authors (https://github.com/Orange-OpenSource/Orange-Boosted-Bootstrap/graphs/contributors)
    * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
    */
  (function (global, factory) {
     module.exports = factory(jquery, tooltip) ;
  }(commonjsGlobal, function ($, Tooltip) {
    $ = $ && $.hasOwnProperty('default') ? $['default'] : $;
    Tooltip = Tooltip && Tooltip.hasOwnProperty('default') ? Tooltip['default'] : Tooltip;

    function _defineProperties(target, props) {
      for (var i = 0; i < props.length; i++) {
        var descriptor = props[i];
        descriptor.enumerable = descriptor.enumerable || false;
        descriptor.configurable = true;
        if ("value" in descriptor) descriptor.writable = true;
        Object.defineProperty(target, descriptor.key, descriptor);
      }
    }

    function _createClass(Constructor, protoProps, staticProps) {
      if (protoProps) _defineProperties(Constructor.prototype, protoProps);
      if (staticProps) _defineProperties(Constructor, staticProps);
      return Constructor;
    }

    function _defineProperty(obj, key, value) {
      if (key in obj) {
        Object.defineProperty(obj, key, {
          value: value,
          enumerable: true,
          configurable: true,
          writable: true
        });
      } else {
        obj[key] = value;
      }

      return obj;
    }

    function _objectSpread(target) {
      for (var i = 1; i < arguments.length; i++) {
        var source = arguments[i] != null ? arguments[i] : {};
        var ownKeys = Object.keys(source);

        if (typeof Object.getOwnPropertySymbols === 'function') {
          ownKeys = ownKeys.concat(Object.getOwnPropertySymbols(source).filter(function (sym) {
            return Object.getOwnPropertyDescriptor(source, sym).enumerable;
          }));
        }

        ownKeys.forEach(function (key) {
          _defineProperty(target, key, source[key]);
        });
      }

      return target;
    }

    function _inheritsLoose(subClass, superClass) {
      subClass.prototype = Object.create(superClass.prototype);
      subClass.prototype.constructor = subClass;
      subClass.__proto__ = superClass;
    }

    /**
     * ------------------------------------------------------------------------
     * Constants
     * ------------------------------------------------------------------------
     */

    var NAME = 'popover';
    var VERSION = '4.3.1';
    var DATA_KEY = 'bs.popover';
    var EVENT_KEY = "." + DATA_KEY;
    var JQUERY_NO_CONFLICT = $.fn[NAME];
    var CLASS_PREFIX = 'bs-popover';
    var BSCLS_PREFIX_REGEX = new RegExp("(^|\\s)" + CLASS_PREFIX + "\\S+", 'g');

    var Default = _objectSpread({}, Tooltip.Default, {
      placement: 'right',
      trigger: 'click',
      content: '',
      template: '<div class="popover" role="tooltip">' + '<div class="arrow"></div>' + '<h3 class="popover-header"></h3>' + '<div class="popover-body"></div></div>'
    });

    var DefaultType = _objectSpread({}, Tooltip.DefaultType, {
      content: '(string|element|function)'
    });

    var ClassName = {
      FADE: 'fade',
      SHOW: 'show'
    };
    var Selector = {
      TITLE: '.popover-header',
      CONTENT: '.popover-body'
    };
    var Event = {
      HIDE: "hide" + EVENT_KEY,
      HIDDEN: "hidden" + EVENT_KEY,
      SHOW: "show" + EVENT_KEY,
      SHOWN: "shown" + EVENT_KEY,
      INSERTED: "inserted" + EVENT_KEY,
      CLICK: "click" + EVENT_KEY,
      FOCUSIN: "focusin" + EVENT_KEY,
      FOCUSOUT: "focusout" + EVENT_KEY,
      MOUSEENTER: "mouseenter" + EVENT_KEY,
      MOUSELEAVE: "mouseleave" + EVENT_KEY
      /**
       * ------------------------------------------------------------------------
       * Class Definition
       * ------------------------------------------------------------------------
       */

    };

    var Popover =
    /*#__PURE__*/
    function (_Tooltip) {
      _inheritsLoose(Popover, _Tooltip);

      function Popover() {
        return _Tooltip.apply(this, arguments) || this;
      }

      var _proto = Popover.prototype;

      // Overrides
      _proto.isWithContent = function isWithContent() {
        return this.getTitle() || this._getContent();
      };

      _proto.addAttachmentClass = function addAttachmentClass(attachment) {
        $(this.getTipElement()).addClass(CLASS_PREFIX + "-" + attachment);
      };

      _proto.getTipElement = function getTipElement() {
        this.tip = this.tip || $(this.config.template)[0];
        return this.tip;
      };

      _proto.setContent = function setContent() {
        var $tip = $(this.getTipElement()); // We use append for html objects to maintain js events

        this.setElementContent($tip.find(Selector.TITLE), this.getTitle());

        var content = this._getContent();

        if (typeof content === 'function') {
          content = content.call(this.element);
        }

        this.setElementContent($tip.find(Selector.CONTENT), content);
        $tip.removeClass(ClassName.FADE + " " + ClassName.SHOW);
      } // Private
      ;

      _proto._getContent = function _getContent() {
        return this.element.getAttribute('data-content') || this.config.content;
      };

      _proto._cleanTipClass = function _cleanTipClass() {
        var $tip = $(this.getTipElement());
        var tabClass = $tip.attr('class').match(BSCLS_PREFIX_REGEX);

        if (tabClass !== null && tabClass.length > 0) {
          $tip.removeClass(tabClass.join(''));
        }
      } // Static
      ;

      Popover._jQueryInterface = function _jQueryInterface(config) {
        return this.each(function () {
          var data = $(this).data(DATA_KEY);

          var _config = typeof config === 'object' ? config : null;

          if (!data && /dispose|hide/.test(config)) {
            return;
          }

          if (!data) {
            data = new Popover(this, _config);
            $(this).data(DATA_KEY, data);
          }

          if (typeof config === 'string') {
            if (typeof data[config] === 'undefined') {
              throw new TypeError("No method named \"" + config + "\"");
            }

            data[config]();
          }
        });
      };

      _createClass(Popover, null, [{
        key: "VERSION",
        // Getters
        get: function get() {
          return VERSION;
        }
      }, {
        key: "Default",
        get: function get() {
          return Default;
        }
      }, {
        key: "NAME",
        get: function get() {
          return NAME;
        }
      }, {
        key: "DATA_KEY",
        get: function get() {
          return DATA_KEY;
        }
      }, {
        key: "Event",
        get: function get() {
          return Event;
        }
      }, {
        key: "EVENT_KEY",
        get: function get() {
          return EVENT_KEY;
        }
      }, {
        key: "DefaultType",
        get: function get() {
          return DefaultType;
        }
      }]);

      return Popover;
    }(Tooltip);
    /**
     * ------------------------------------------------------------------------
     * jQuery
     * ------------------------------------------------------------------------
     */


    $.fn[NAME] = Popover._jQueryInterface;
    $.fn[NAME].Constructor = Popover;

    $.fn[NAME].noConflict = function () {
      $.fn[NAME] = JQUERY_NO_CONFLICT;
      return Popover._jQueryInterface;
    };

    return Popover;

  }));

  });

  var classes$4 = {
    priceAmount: "ob1-price-amount",
    priceAmountInverse: "ob1-price-amount-inverse",
    pricePromoDurationByMonth: "ob1-price-promo-duration-by-month",
    priceAmountCustom: "ob1-price-amount-custom",
    pricePromoDurationByMonthCustom: "ob1-price-promo-duration-by-month-custom",
    priceWithoutPromo: "ob1-price-without-promo",
    // deprecated
    priceAmountDeprecated: "price-amount",
    priceAmountInverseDeprecated: "price-amount-inverse",
    pricePromoDurationByMonthDeprecated: "price-promo-duration-by-month",
    priceAmountCustomDeprecated: "price-amount-custom",
    pricePromoDurationByMonthCustomDeprecated: "price-promo-duration-by-month-custom"
  };
  var texts = {
    euros: "€",
    space: " ",
    nonBreakingSpace: "\xA0",
    narrowNonBreakingSpace: "\u202F"
  };
  var separators = {
    dot: ".",
    comma: ",",
    zeroCentsByUnit: "0€",
    zeroCentsByDecade: "00€"
  };
  var pricesToConvert = [classes$4.priceAmount, classes$4.priceAmountInverse, classes$4.pricePromoDurationByMonth, classes$4.priceAmountCustom, classes$4.pricePromoDurationByMonthCustom, classes$4.priceWithoutPromo, // deprecated
  classes$4.priceAmountDeprecated, classes$4.priceAmountInverseDeprecated, classes$4.pricePromoDurationByMonthDeprecated, classes$4.priceAmountCustomDeprecated, classes$4.pricePromoDurationByMonthCustomDeprecated];

  var Price = /*#__PURE__*/function (_Ob1Component) {
    _inheritsLoose(Price, _Ob1Component);

    function Price(container, parameters) {
      return _Ob1Component.call(this, container, "Price", parameters) || this;
    }
    /**
     * Initialisation du composant price
     *
     * @param {HTMLElement} container le noeud DOM sur lequel est instancié le composant
     * @param {object} parameters les paramètres de ce composant
     */


    var _proto = Price.prototype;

    _proto.init = function init(container, parameters) {
      _Ob1Component.prototype.init.call(this, container, parameters); // Si le prix a un point comme séparateur entre la partie entière et les centimes, on remplace les points par des virgules


      this.replacePointByComma(); // On supprime les centimes si ils sont à 0

      this.removeCentsIfRoundFigure(); // On ajoute un espace fine insécable entre le montant et le symbole €

      this.addNarrowNonBreakingSpace();
    }
    /**
     * On ne doit avoir que des prix avec une virgule comme séparateur entre la partie entière et les centimes
     */
    ;

    _proto.replacePointByComma = function replacePointByComma() {
      var _this = this;

      pricesToConvert.forEach(function (priceToConvert) {
        var pricesAmounts = _this.container.getElementsByClassName(priceToConvert);

        Array.from(pricesAmounts).forEach(function (priceAmounts) {
          priceAmounts.innerText = priceAmounts.innerText.replace(separators.dot, separators.comma);
        });
      });
    }
    /**
     * On ne doit avoir que des prix avec une virgule comme séparateur entre la partie entière et les centimes
     */
    ;

    _proto.removeCentsIfRoundFigure = function removeCentsIfRoundFigure() {
      var _this2 = this;

      pricesToConvert.forEach(function (priceToConvert) {
        var pricesAmounts = _this2.container.getElementsByClassName(priceToConvert);

        Array.from(pricesAmounts).forEach(function (priceAmounts) {
          var priceValues = priceAmounts.innerText.split(separators.comma); // On enlève les centimes si elles sont à 0 ou 00

          if (priceValues[1] && priceValues[1].substring(0, 2) === separators.zeroCentsByUnit) {
            var values = priceAmounts.innerText.split(separators.comma + separators.zeroCentsByUnit);
            priceAmounts.innerText = values[0] + texts.euros + values[1];
          }

          if (priceValues[1] && priceValues[1].substring(0, 3) === separators.zeroCentsByDecade) {
            var _values = priceAmounts.innerText.split(separators.comma + separators.zeroCentsByDecade);

            priceAmounts.innerText = _values[0] + texts.euros + _values[1];
          }
        });
      });
    }
    /**
     * Ajout d'un espace fine insécable entre le montant et le symbole €
     * Remplace les espaces classiques et insécables par des espaces fine insécables
     */
    ;

    _proto.addNarrowNonBreakingSpace = function addNarrowNonBreakingSpace() {
      var _this3 = this;

      pricesToConvert.forEach(function (priceToConvert) {
        var pricesAmounts = _this3.container.getElementsByClassName(priceToConvert);

        Array.from(pricesAmounts).forEach(function (priceAmounts) {
          var amount = priceAmounts.innerText;
          var indexOfEuros = amount.indexOf(texts.euros);

          if (amount[indexOfEuros - 1] === texts.narrowNonBreakingSpace) {
            return;
          } else if (amount[indexOfEuros - 1] === texts.space) {
            priceAmounts.innerText = amount.replace(texts.space, texts.narrowNonBreakingSpace);
          } else if (amount[indexOfEuros - 1] === texts.nonBreakingSpace) {
            priceAmounts.innerText = amount.replace(texts.nonBreakingSpace, texts.narrowNonBreakingSpace);
          } else {
            priceAmounts.innerText = [amount.slice(0, indexOfEuros), texts.narrowNonBreakingSpace, amount.slice(indexOfEuros)].join("");
          }
        });
      });
    };

    return Price;
  }(Ob1Component); // rattachement au contexte window pour pouvoir l'utiliser en dehors du JS


  window.Price = Price;

  var prioritynav = createCommonjsModule(function (module, exports) {
  /*!
    * Boosted v4.3.1 (https://boosted.orange.com)
    * Copyright 2014-2019 The Boosted Authors
    * Copyright 2014-2019 Orange
    * Licensed under MIT (https://github.com/orange-opensource/orange-boosted-bootstrap/blob/master/LICENSE)
    * This a fork of Bootstrap : Initial license below
    * Bootstrap prioritynav.js v4.3.1 (https://boosted.orange.com)
    * Copyright 2011-2019 The Boosted Authors (https://github.com/Orange-OpenSource/Orange-Boosted-Bootstrap/graphs/contributors)
    * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
    */
  (function (global, factory) {
     module.exports = factory(jquery) ;
  }(commonjsGlobal, function ($) {
    $ = $ && $.hasOwnProperty('default') ? $['default'] : $;

    function _defineProperties(target, props) {
      for (var i = 0; i < props.length; i++) {
        var descriptor = props[i];
        descriptor.enumerable = descriptor.enumerable || false;
        descriptor.configurable = true;
        if ("value" in descriptor) descriptor.writable = true;
        Object.defineProperty(target, descriptor.key, descriptor);
      }
    }

    function _createClass(Constructor, protoProps, staticProps) {
      if (protoProps) _defineProperties(Constructor.prototype, protoProps);
      if (staticProps) _defineProperties(Constructor, staticProps);
      return Constructor;
    }

    /**
     * ------------------------------------------------------------------------
     * Constants
     * ------------------------------------------------------------------------
     */

    var NAME = 'prioritynav';
    var VERSION = '4.3.1';
    var DATA_KEY = 'bs.prioritynav';
    var JQUERY_NO_CONFLICT = $.fn[NAME];
    var RESIZE_DURATION = 500;
    var TAB_KEYCODE = 9;
    var Event = {
      RESIZE: 'resize',
      FOCUS: 'focus'
    };
    var ClassName = {
      PRIORITY: 'priority',
      HIDE: 'sr-only',
      RESIZING: 'resizing'
    };
    var Selector = {
      NAV_ELEMENTS: 'li:not(\'.overflow-nav\')',
      FIRST_ELEMENT: 'li:first',
      PRIORITY_ELEMENT: '.priority'
    };
    var MenuLabelDefault = 'More';

    function MenuTemplate(MenuLabel) {
      return "\n  <li class=\"overflow-nav nav-item dropdown\">\n      <a href=\"#\" class=\"dropdown-toggle nav-link\" data-toggle=\"dropdown\" role=\"button\" aria-haspopup=\"true\">" + MenuLabel + "</a>\n      <ul class=\"overflow-nav-list dropdown-menu dropdown-menu-right\"></ul>\n  </li>\n";
    }
    /**
     * ------------------------------------------------------------------------
     * Class Definition
     * ------------------------------------------------------------------------
     */


    var PriorityNav =
    /*#__PURE__*/
    function () {
      function PriorityNav(element, config) {
        this._element = element;
        this._config = config;

        if ($(element).is('ul')) {
          this._$menu = $(element);
        } else {
          this._$menu = $(element).find('ul').first();
        }

        this._initMenu();

        this._$allNavElements = this._$menu.find(Selector.NAV_ELEMENTS);

        this._bindUIActions();

        this._setupMenu();
      } // getters


      var _proto = PriorityNav.prototype;

      // public
      // private
      _proto._initMenu = function _initMenu() {
        var MenuLabel = this._config;

        if (typeof MenuLabel === 'undefined') {
          MenuLabel = MenuLabelDefault;
        } // add menu template


        this._$menu.append(MenuTemplate(MenuLabel));
      };

      _proto._setupMenu = function _setupMenu() {
        var $allNavElements = this._$allNavElements; // Checking top position of first item (sometimes changes)

        var firstPos = this._$menu.find(Selector.FIRST_ELEMENT).position(); // Empty collection in which to put menu items to move


        var $wrappedElements = $(); // Used to snag the previous menu item in addition to ones that have wrapped

        var first = true; // Loop through all the nav items...

        this._$allNavElements.each(function (i) {
          var $elm = $(this); // ...in which to find wrapped elements

          var pos = $elm.position();

          if (pos.top !== firstPos.top) {
            // If element is wrapped, add it to set
            $wrappedElements = $wrappedElements.add($elm); // Add the previous one too, if first

            if (first) {
              $wrappedElements = $wrappedElements.add($allNavElements.eq(i - 1));
              first = false;
            }
          }
        });

        if ($wrappedElements.length) {
          // Clone set before altering
          var newSet = $wrappedElements.clone(); // Hide ones that we're moving

          $wrappedElements.addClass(ClassName.HIDE);
          $wrappedElements.find('.nav-link').attr('tabindex', -1); // Add wrapped elements to dropdown

          this._$menu.find('.overflow-nav-list').append(newSet); // Show new menu


          this._$menu.find('.overflow-nav').addClass('show-inline-block'); // Make overflow visible again so dropdown can be seen.


          this._$menu.find('.o-nav-local').css('overflow', 'visible'); // Check if menu doesn't overflow after process


          if (this._$menu.find('.overflow-nav').position().top !== firstPos.top) {
            var $item = $(this._element).find("." + ClassName.HIDE).first().prev();
            var $itemDuplicate = $item.clone();
            $item.addClass(ClassName.HIDE);
            $item.find('.nav-link').attr('tabindex', -1);

            this._$menu.find('.overflow-nav-list').prepend($itemDuplicate);
          }
        } // hide menu from AT


        this._$menu.find('.overflow-nav').attr('aria-hidden', true);
      };

      _proto._tearDown = function _tearDown() {
        this._$menu.find('.overflow-nav-list').empty();

        this._$menu.find('.overflow-nav').removeClass('show-inline-block');

        this._$allNavElements.removeClass(ClassName.HIDE);

        this._$allNavElements.find('.nav-link').attr('tabindex', 0);
      };

      _proto._bindUIActions = function _bindUIActions() {
        var _this = this;

        $(window).on(Event.RESIZE, function () {
          _this._$menu.addClass(ClassName.RESIZING);

          setTimeout(function () {
            _this._tearDown();

            _this._setupMenu();

            _this._$menu.removeClass(ClassName.RESIZING);
          }, RESIZE_DURATION);
        });

        this._$menu.find('.overflow-nav .dropdown-toggle').on('keyup', function (e) {
          if (e.which === TAB_KEYCODE) {
            $(e.target).dropdown('toggle');
          }
        });
      } // static
      ;

      PriorityNav._jQueryInterface = function _jQueryInterface(config) {
        return this.each(function () {
          var data = $(this).data(DATA_KEY);

          if (!data) {
            data = new PriorityNav(this, config);
            $(this).data(DATA_KEY, data);
          }

          if (typeof config !== 'undefined' && config) {
            if (typeof config !== 'string') {
              throw new TypeError('Priority nav label type must be string');
            }
          }
        });
      };

      _createClass(PriorityNav, null, [{
        key: "VERSION",
        get: function get() {
          return VERSION;
        }
      }]);

      return PriorityNav;
    }();
    /**
     * ------------------------------------------------------------------------
     * jQuery
     * ------------------------------------------------------------------------
     */


    $.fn[NAME] = PriorityNav._jQueryInterface;
    $.fn[NAME].Constructor = PriorityNav;

    $.fn[NAME].noConflict = function () {
      $.fn[NAME] = JQUERY_NO_CONFLICT;
      return PriorityNav._jQueryInterface;
    };

    return PriorityNav;

  }));

  });

  var spinnerDeterminedTagNames = {
    DIV: "div"
  };
  var spinerDeterminedClasses = {
    SPINNER: "ob1-spinner-determined",
    LOADER1: "ob1-spinner-determined-loader1",
    LOADER2: "ob1-spinner-determined-loader2"
  };
  var spinerDeterminedAttributes = {
    TABINDEX: "tabindex",
    TABINDEX_NEGATIVE: "-1",
    ARIA_LABEL: "aria-label",
    ARIA_LABEL_SPINNER: "Chargement en cours"
  };

  var SpinnerDetermined = /*#__PURE__*/function (_Ob1Component) {
    _inheritsLoose(SpinnerDetermined, _Ob1Component);

    function SpinnerDetermined(container, parameters) {
      return _Ob1Component.call(this, container, "SpinnerDetermined", parameters) || this;
    }
    /**
     * Initialisation du composant
     * @param {HTMLElement} container - L'élément représentant le spinner
     * @param {object} parameters les paramètres d'instanciation de ce composant
     */


    var _proto = SpinnerDetermined.prototype;

    _proto.init = function init(container, parameters) {
      _Ob1Component.prototype.init.call(this, container, parameters); // On postionne le focus sur l'élément pour lancer la vocalisation


      this.container.setAttribute(spinerDeterminedAttributes.ARIA_LABEL, spinerDeterminedAttributes.ARIA_LABEL_SPINNER);
      this.container.setAttribute(spinerDeterminedAttributes.TABINDEX, spinerDeterminedAttributes.TABINDEX_NEGATIVE);
      this.container.focus(); // On crée les 2 loaders nécessaires à l'animation

      this.loader1 = this.createLoader(spinerDeterminedClasses.LOADER1);
      this.loader2 = this.createLoader(spinerDeterminedClasses.LOADER2);
      this.container.appendChild(this.loader1);
      this.container.appendChild(this.loader2); // On applique une temporisation avant le démarrage du scale (disparition du cercle)

      this.container.style.animationDelay = this.container.dataset.spinnerdeterminedTimer + "s"; // On applique une durée à l'animation du premier loader

      this.loader1.style.animationDuration = this.container.dataset.spinnerdeterminedTimer / 2 + "s"; // On applique une durée et une temporisation à l'animation du deuxième loader

      this.loader2.style.animationDelay = this.container.dataset.spinnerdeterminedTimer / 2 + "s";
      this.loader2.style.animationDuration = this.container.dataset.spinnerdeterminedTimer / 2 + "s";
    }
    /**
     * Masque le spinner
     */
    ;

    _proto.hide = function hide() {
      this.container.classList.add("d-none");
    }
    /**
     * Affiche le spinner
     */
    ;

    _proto.show = function show() {
      this.container.classList.remove("d-none");
    }
    /**
     * Lance l'animation du spinner
     */
    ;

    _proto.reload = function reload() {
      this.container.classList.remove(spinerDeterminedClasses.SPINNER);
      void this.container.offsetWidth;
      this.container.classList.add(spinerDeterminedClasses.SPINNER);
    }
    /**
     * Création d'un élément loader
     * @param {String} className - Le nom de la classe appliquée sur l'élément
     */
    ;

    _proto.createLoader = function createLoader(className) {
      var loader = document.createElement(spinnerDeterminedTagNames.DIV);
      loader.classList.add(className);
      return loader;
    };

    return SpinnerDetermined;
  }(Ob1Component); // rattachement au contexte window pour pouvoir l'utiliser en dehors du JS


  window.SpinnerDetermined = SpinnerDetermined;

  var CLASSES = {
    PROGRESS_BAR_DETERMINED: "ob1-progress-bar-determined"
  };
  var ATTRIBUTES$1 = {
    ARIA_LABEL: "aria-label",
    ARIA_LABEL_PROGRESS_BAR: "Chargement en cours"
  };

  var ProgressBarDetermined = /*#__PURE__*/function (_Ob1Component) {
    _inheritsLoose(ProgressBarDetermined, _Ob1Component);

    function ProgressBarDetermined(container, parameters) {
      return _Ob1Component.call(this, container, "ProgressBarDetermined", parameters) || this;
    }
    /**
     * Initialisation du composant
     * @param {HTMLElement} container - L'élément représentant la progress bar à temps déterminé
     * @param {object} parameters les paramètres d'instanciation de ce composant
     */


    var _proto = ProgressBarDetermined.prototype;

    _proto.init = function init(container, parameters) {
      _Ob1Component.prototype.init.call(this, container, parameters); // On récupère la durée d'animation passé en data-attribute


      var duration = this.container.dataset.timer; // Si la barre de progression est utilisée dans un bouton, on doit créer la div contenant la barre de progression à l'intérieur du bouton

      var progressBar = this.initialisation(); // On positionne le focus sur l'élément pour lancer la vocalisation

      this.container.setAttribute(ATTRIBUTES$1.ARIA_LABEL, ATTRIBUTES$1.ARIA_LABEL_PROGRESS_BAR);
      this.container.focus(); // La durée de l'animation passée dans l'attibut data-time est appliquée

      progressBar.style.animationDuration = "500ms, " + duration + "s, 500ms";
      progressBar.style.animationDelay = "0s, 500ms, " + duration + ".5s";
      progressBar.firstChild.style.animationDuration = duration + "s";
    }
    /**
     * Initialisation de la barre de progression
     */
    ;

    _proto.initialisation = function initialisation() {
      var progressBar; // Si on doit afficher la barre de progression dans un bouton

      if (this.container.classList.contains("btn")) {
        var button = this.container;
        var progressBarDetermined = document.createElement("span");
        progressBarDetermined.classList.add(CLASSES.PROGRESS_BAR_DETERMINED);
        button.appendChild(progressBarDetermined);
        progressBar = progressBarDetermined;
      } else {
        progressBar = this.container;
      } // Ajout de l'élément inner


      var innerBar = document.createElement("span");
      innerBar.classList.add("ob1-progress-bar-determined-inner");
      progressBar.appendChild(innerBar);
      return progressBar;
    }
    /**
     * Reinitialisation de la barre de progression présente dans un bouton
     */
    ;

    _proto.progressBarInButtonReinitialisation = function progressBarInButtonReinitialisation() {
      this.container.removeAttribute("data-ob1-component");
      this.container.removeAttribute("data-timer");
      this.container.removeAttribute("data-ref-progress-bar-determined");
      this.container.removeAttribute(ATTRIBUTES$1.ARIA_LABEL);

      if (this.container.querySelector(".ob1-progress-bar-determined") !== null) {
        this.container.removeChild(this.container.querySelector(".ob1-progress-bar-determined"));
      }
    };

    return ProgressBarDetermined;
  }(Ob1Component); // rattachement au contexte window pour pouvoir l'utiliser en dehors du JS


  window.ProgressBarDetermined = ProgressBarDetermined;

  // Exporte tous les types d'indicateurs de progressions

  var index = /*#__PURE__*/Object.freeze({
    __proto__: null
  });

  var classes$5 = {
    dBlock: "d-block"
  };
  var listenersTypes = {
    keyUp: "keyup",
    focus: "focus",
    blur: "blur"
  };
  var selectors$1 = {
    textField: ".ob1-promotional-code-content .form-control",
    addPromotionalCode: ".ob1-add-promotional-code:not(.ob1-loading)"
  };

  var PromotionalCode = /*#__PURE__*/function (_Ob1Component) {
    _inheritsLoose(PromotionalCode, _Ob1Component);

    function PromotionalCode(container, parameters) {
      return _Ob1Component.call(this, container, "PromotionalCode", parameters) || this;
    }
    /**
     * Initialisation du composant
     *
     * @param {HTMLElement} container le noeud DOM sur lequel est instancié le composant
     * @param {object} parameters les paramètres d'instanciation de ce composant
     */


    var _proto = PromotionalCode.prototype;

    _proto.init = function init(container, parameters) {
      var _this = this;

      _Ob1Component.prototype.init.call(this, container, parameters);

      this.promotionalCodeTextField = this.container.querySelector(selectors$1.textField); // Gestion de l'affichage du bouton d'ajout

      if (this.promotionalCodeTextField !== null) {
        this.promotionalCodeTextField.addEventListener(listenersTypes.keyUp, function () {
          return _this.buttonDisplayManager(true);
        });
        this.promotionalCodeTextField.addEventListener(listenersTypes.focus, function () {
          return _this.buttonDisplayManager(true);
        });
        this.promotionalCodeTextField.addEventListener(listenersTypes.blur, function () {
          return _this.buttonDisplayManager(false);
        });
      }
    }
    /**
     * Décharge le composant
     */
    ;

    _proto.dispose = function dispose() {
      // suppression de tous les event listeners qui ont été créés
      this.promotionalCodeTextField.removeEventListener(listenersTypes.keyUp, this.buttonDisplayManager(true));
      this.promotionalCodeTextField.removeEventListener(listenersTypes.focus, this.buttonDisplayManager(true));
      this.promotionalCodeTextField.removeEventListener(listenersTypes.blur, this.buttonDisplayManager(false)); // on appelle la méthode de suppression de composant d'Ob1Component (obligatoire)

      _Ob1Component.prototype.dispose.call(this);
    }
    /**
     * Gestionnaire de l'affichage du bouton d'ajout du code promotionnel
     *
     * @param {boolean} focused précise si le focus est postionné sur le text field
     */
    ;

    _proto.buttonDisplayManager = function buttonDisplayManager(focused) {
      var addPromotionnalCode = this.container.querySelector(selectors$1.addPromotionalCode);

      if (addPromotionnalCode !== null) {
        if (this.promotionalCodeTextField.value !== "" || focused) {
          addPromotionnalCode.classList.add(classes$5.dBlock);
        } else {
          addPromotionnalCode.classList.remove(classes$5.dBlock);
        }
      }
    };

    return PromotionalCode;
  }(Ob1Component);

  window.PromotionalCode = PromotionalCode;

  var scrollup = createCommonjsModule(function (module, exports) {
  /*!
    * Boosted v4.3.1 (https://boosted.orange.com)
    * Copyright 2014-2019 The Boosted Authors
    * Copyright 2014-2019 Orange
    * Licensed under MIT (https://github.com/orange-opensource/orange-boosted-bootstrap/blob/master/LICENSE)
    * This a fork of Bootstrap : Initial license below
    * Bootstrap scrollup.js v4.3.1 (https://boosted.orange.com)
    * Copyright 2011-2019 The Boosted Authors (https://github.com/Orange-OpenSource/Orange-Boosted-Bootstrap/graphs/contributors)
    * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
    */
  (function (global, factory) {
     module.exports = factory(jquery) ;
  }(commonjsGlobal, function ($) {
    $ = $ && $.hasOwnProperty('default') ? $['default'] : $;

    function _defineProperties(target, props) {
      for (var i = 0; i < props.length; i++) {
        var descriptor = props[i];
        descriptor.enumerable = descriptor.enumerable || false;
        descriptor.configurable = true;
        if ("value" in descriptor) descriptor.writable = true;
        Object.defineProperty(target, descriptor.key, descriptor);
      }
    }

    function _createClass(Constructor, protoProps, staticProps) {
      if (protoProps) _defineProperties(Constructor.prototype, protoProps);
      if (staticProps) _defineProperties(Constructor, staticProps);
      return Constructor;
    }

    /**
     * ------------------------------------------------------------------------
     * Constants
     * ------------------------------------------------------------------------
     */

    var NAME = 'scrollup';
    var VERSION = '4.3.1';
    var DATA_KEY = 'bs.scrollup';
    var EVENT_KEY = "." + DATA_KEY;
    var DATA_API_KEY = '.data-api';
    var JQUERY_NO_CONFLICT = $.fn[NAME];
    var SCROLLANIMATE = 500;
    var Default = {
      offset: 10,
      method: 'auto',
      target: ''
    };
    var Event = {
      SCROLL: "scroll" + EVENT_KEY,
      CLICK_SCROLL: "click" + EVENT_KEY,
      LOAD_DATA_API: "load" + EVENT_KEY + DATA_API_KEY
    };
    var ClassName = {
      SCROLL_TOP: 'o-scroll-up'
    };
    var Selector = {
      SCROLL_TOP: '.o-scroll-up:not(.static)'
      /**
       * ------------------------------------------------------------------------
       * Class Definition
       * ------------------------------------------------------------------------
       */

    };

    var ScrollUp =
    /*#__PURE__*/
    function () {
      function ScrollUp(element) {
        this._element = element;
        this._scrollElement = window;
        $(window).on(Event.SCROLL, $.proxy(this._process, this));
        $(Selector.SCROLL_TOP).on(Event.CLICK_SCROLL, $.proxy(this._backToTop, this));
        $(this._element).addClass('is-fixed');

        this._process();
      } // getters


      var _proto = ScrollUp.prototype;

      // public
      _proto.dispose = function dispose() {
        $.removeData(this._element, DATA_KEY);
        $(this._scrollElement).off(EVENT_KEY);
        this._element = null;
        this._scrollElement = null;
      } // private
      ;

      _proto._process = function _process() {
        if ($(this._scrollElement).scrollTop() > Number($(this._scrollElement).height())) {
          $(Selector.SCROLL_TOP).show();
        } else {
          $(Selector.SCROLL_TOP).hide();
        }
      };

      _proto._clear = function _clear() {
        $(this._selector).filter(Selector.ACTIVE).removeClass(ClassName.ACTIVE);
      };

      _proto._backToTop = function _backToTop() {
        if (typeof $.animate === 'function') {
          $('html, body').animate({
            scrollTop: 0
          }, SCROLLANIMATE);
        } else {
          $('html, body').scrollTop(0);
        }
      } // static
      ;

      ScrollUp._jQueryInterface = function _jQueryInterface() {
        return this.each(function () {
          var data = $(this).data(DATA_KEY);

          if (!data) {
            data = new ScrollUp(this);
            $(this).data(DATA_KEY, data);
          }
        });
      };

      _createClass(ScrollUp, null, [{
        key: "VERSION",
        get: function get() {
          return VERSION;
        }
      }, {
        key: "Default",
        get: function get() {
          return Default;
        }
      }]);

      return ScrollUp;
    }();
    /**
     * ------------------------------------------------------------------------
     * Data Api implementation
     * ------------------------------------------------------------------------
     */


    $(window).on(Event.LOAD_DATA_API, function () {
      var scrollUps = $.makeArray($(Selector.SCROLL_TOP));

      for (var i = scrollUps.length; i--;) {
        var $scrollup = $(scrollUps[i]);

        ScrollUp._jQueryInterface.call($scrollup, $scrollup.data());
      }
    });
    /**
     * ------------------------------------------------------------------------
     * jQuery
     * ------------------------------------------------------------------------
     */

    $.fn[NAME] = ScrollUp._jQueryInterface;
    $.fn[NAME].Constructor = ScrollUp;

    $.fn[NAME].noConflict = function () {
      $.fn[NAME] = JQUERY_NO_CONFLICT;
      return ScrollUp._jQueryInterface;
    };

    return ScrollUp;

  }));

  });

  var scrollspy = createCommonjsModule(function (module, exports) {
  /*!
    * Boosted v4.3.1 (https://boosted.orange.com)
    * Copyright 2014-2019 The Boosted Authors
    * Copyright 2014-2019 Orange
    * Licensed under MIT (https://github.com/orange-opensource/orange-boosted-bootstrap/blob/master/LICENSE)
    * This a fork of Bootstrap : Initial license below
    * Bootstrap scrollspy.js v4.3.1 (https://boosted.orange.com)
    * Copyright 2011-2019 The Boosted Authors (https://github.com/Orange-OpenSource/Orange-Boosted-Bootstrap/graphs/contributors)
    * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
    */
  (function (global, factory) {
     module.exports = factory(jquery, util) ;
  }(commonjsGlobal, function ($, Util) {
    $ = $ && $.hasOwnProperty('default') ? $['default'] : $;
    Util = Util && Util.hasOwnProperty('default') ? Util['default'] : Util;

    function _defineProperties(target, props) {
      for (var i = 0; i < props.length; i++) {
        var descriptor = props[i];
        descriptor.enumerable = descriptor.enumerable || false;
        descriptor.configurable = true;
        if ("value" in descriptor) descriptor.writable = true;
        Object.defineProperty(target, descriptor.key, descriptor);
      }
    }

    function _createClass(Constructor, protoProps, staticProps) {
      if (protoProps) _defineProperties(Constructor.prototype, protoProps);
      if (staticProps) _defineProperties(Constructor, staticProps);
      return Constructor;
    }

    function _defineProperty(obj, key, value) {
      if (key in obj) {
        Object.defineProperty(obj, key, {
          value: value,
          enumerable: true,
          configurable: true,
          writable: true
        });
      } else {
        obj[key] = value;
      }

      return obj;
    }

    function _objectSpread(target) {
      for (var i = 1; i < arguments.length; i++) {
        var source = arguments[i] != null ? arguments[i] : {};
        var ownKeys = Object.keys(source);

        if (typeof Object.getOwnPropertySymbols === 'function') {
          ownKeys = ownKeys.concat(Object.getOwnPropertySymbols(source).filter(function (sym) {
            return Object.getOwnPropertyDescriptor(source, sym).enumerable;
          }));
        }

        ownKeys.forEach(function (key) {
          _defineProperty(target, key, source[key]);
        });
      }

      return target;
    }

    /**
     * ------------------------------------------------------------------------
     * Constants
     * ------------------------------------------------------------------------
     */

    var NAME = 'scrollspy';
    var VERSION = '4.3.1';
    var DATA_KEY = 'bs.scrollspy';
    var EVENT_KEY = "." + DATA_KEY;
    var DATA_API_KEY = '.data-api';
    var JQUERY_NO_CONFLICT = $.fn[NAME];
    var Default = {
      offset: 10,
      method: 'auto',
      target: ''
    };
    var DefaultType = {
      offset: 'number',
      method: 'string',
      target: '(string|element)'
    };
    var Event = {
      ACTIVATE: "activate" + EVENT_KEY,
      SCROLL: "scroll" + EVENT_KEY,
      LOAD_DATA_API: "load" + EVENT_KEY + DATA_API_KEY
    };
    var ClassName = {
      DROPDOWN_ITEM: 'dropdown-item',
      DROPDOWN_MENU: 'dropdown-menu',
      ACTIVE: 'active'
    };
    var Selector = {
      DATA_SPY: '[data-spy="scroll"]',
      ACTIVE: '.active',
      NAV_LIST_GROUP: '.nav, .list-group',
      NAV_LINKS: '.nav-link',
      NAV_ITEMS: '.nav-item',
      LIST_ITEMS: '.list-group-item',
      DROPDOWN: '.dropdown',
      DROPDOWN_ITEMS: '.dropdown-item',
      DROPDOWN_TOGGLE: '.dropdown-toggle'
    };
    var OffsetMethod = {
      OFFSET: 'offset',
      POSITION: 'position'
      /**
       * ------------------------------------------------------------------------
       * Class Definition
       * ------------------------------------------------------------------------
       */

    };

    var ScrollSpy =
    /*#__PURE__*/
    function () {
      function ScrollSpy(element, config) {
        var _this = this;

        this._element = element;
        this._scrollElement = element.tagName === 'BODY' ? window : element;
        this._config = this._getConfig(config);
        this._selector = this._config.target + " " + Selector.NAV_LINKS + "," + (this._config.target + " " + Selector.LIST_ITEMS + ",") + (this._config.target + " " + Selector.DROPDOWN_ITEMS);
        this._offsets = [];
        this._targets = [];
        this._activeTarget = null;
        this._scrollHeight = 0;
        $(this._scrollElement).on(Event.SCROLL, function (event) {
          return _this._process(event);
        });
        this.refresh();

        this._process();
      } // Getters


      var _proto = ScrollSpy.prototype;

      // Public
      _proto.refresh = function refresh() {
        var _this2 = this;

        var autoMethod = this._scrollElement === this._scrollElement.window ? OffsetMethod.OFFSET : OffsetMethod.POSITION;
        var offsetMethod = this._config.method === 'auto' ? autoMethod : this._config.method;
        var offsetBase = offsetMethod === OffsetMethod.POSITION ? this._getScrollTop() : 0;
        this._offsets = [];
        this._targets = [];
        this._scrollHeight = this._getScrollHeight();
        var targets = [].slice.call(document.querySelectorAll(this._selector));
        targets.map(function (element) {
          var target;
          var targetSelector = Util.getSelectorFromElement(element);

          if (targetSelector) {
            target = document.querySelector(targetSelector);
          }

          if (target) {
            var targetBCR = target.getBoundingClientRect();

            if (targetBCR.width || targetBCR.height) {
              // TODO (fat): remove sketch reliance on jQuery position/offset
              return [$(target)[offsetMethod]().top + offsetBase, targetSelector];
            }
          }

          return null;
        }).filter(function (item) {
          return item;
        }).sort(function (a, b) {
          return a[0] - b[0];
        }).forEach(function (item) {
          _this2._offsets.push(item[0]);

          _this2._targets.push(item[1]);
        });
      };

      _proto.dispose = function dispose() {
        $.removeData(this._element, DATA_KEY);
        $(this._scrollElement).off(EVENT_KEY);
        this._element = null;
        this._scrollElement = null;
        this._config = null;
        this._selector = null;
        this._offsets = null;
        this._targets = null;
        this._activeTarget = null;
        this._scrollHeight = null;
      } // Private
      ;

      _proto._getConfig = function _getConfig(config) {
        config = _objectSpread({}, Default, typeof config === 'object' && config ? config : {});

        if (typeof config.target !== 'string') {
          var id = $(config.target).attr('id');

          if (!id) {
            id = Util.getUID(NAME);
            $(config.target).attr('id', id);
          }

          config.target = "#" + id;
        }

        Util.typeCheckConfig(NAME, config, DefaultType);
        return config;
      };

      _proto._getScrollTop = function _getScrollTop() {
        return this._scrollElement === window ? this._scrollElement.pageYOffset : this._scrollElement.scrollTop;
      };

      _proto._getScrollHeight = function _getScrollHeight() {
        return this._scrollElement.scrollHeight || Math.max(document.body.scrollHeight, document.documentElement.scrollHeight);
      };

      _proto._getOffsetHeight = function _getOffsetHeight() {
        return this._scrollElement === window ? window.innerHeight : this._scrollElement.getBoundingClientRect().height;
      };

      _proto._process = function _process() {
        var scrollTop = this._getScrollTop() + this._config.offset;

        var scrollHeight = this._getScrollHeight();

        var maxScroll = this._config.offset + scrollHeight - this._getOffsetHeight();

        if (this._scrollHeight !== scrollHeight) {
          this.refresh();
        }

        if (scrollTop >= maxScroll) {
          var target = this._targets[this._targets.length - 1];

          if (this._activeTarget !== target) {
            this._activate(target);
          }

          return;
        }

        if (this._activeTarget && scrollTop < this._offsets[0] && this._offsets[0] > 0) {
          this._activeTarget = null;

          this._clear();

          return;
        }

        var offsetLength = this._offsets.length;

        for (var i = offsetLength; i--;) {
          var isActiveTarget = this._activeTarget !== this._targets[i] && scrollTop >= this._offsets[i] && (typeof this._offsets[i + 1] === 'undefined' || scrollTop < this._offsets[i + 1]);

          if (isActiveTarget) {
            this._activate(this._targets[i]);
          }
        }
      };

      _proto._activate = function _activate(target) {
        this._activeTarget = target;

        this._clear();

        var queries = this._selector.split(',').map(function (selector) {
          return selector + "[data-target=\"" + target + "\"]," + selector + "[href=\"" + target + "\"]";
        });

        var $link = $([].slice.call(document.querySelectorAll(queries.join(','))));

        if ($link.hasClass(ClassName.DROPDOWN_ITEM)) {
          $link.closest(Selector.DROPDOWN).find(Selector.DROPDOWN_TOGGLE).addClass(ClassName.ACTIVE);
          $link.addClass(ClassName.ACTIVE);
        } else {
          // Set triggered link as active
          $link.addClass(ClassName.ACTIVE); // Set triggered links parents as active
          // With both <ul> and <nav> markup a parent is the previous sibling of any nav ancestor

          $link.parents(Selector.NAV_LIST_GROUP).prev(Selector.NAV_LINKS + ", " + Selector.LIST_ITEMS).addClass(ClassName.ACTIVE); // Handle special case when .nav-link is inside .nav-item

          $link.parents(Selector.NAV_LIST_GROUP).prev(Selector.NAV_ITEMS).children(Selector.NAV_LINKS).addClass(ClassName.ACTIVE);
        }

        $(this._scrollElement).trigger(Event.ACTIVATE, {
          relatedTarget: target
        });
      };

      _proto._clear = function _clear() {
        [].slice.call(document.querySelectorAll(this._selector)).filter(function (node) {
          return node.classList.contains(ClassName.ACTIVE);
        }).forEach(function (node) {
          return node.classList.remove(ClassName.ACTIVE);
        });
      } // Static
      ;

      ScrollSpy._jQueryInterface = function _jQueryInterface(config) {
        return this.each(function () {
          var data = $(this).data(DATA_KEY);

          var _config = typeof config === 'object' && config;

          if (!data) {
            data = new ScrollSpy(this, _config);
            $(this).data(DATA_KEY, data);
          }

          if (typeof config === 'string') {
            if (typeof data[config] === 'undefined') {
              throw new TypeError("No method named \"" + config + "\"");
            }

            data[config]();
          }
        });
      };

      _createClass(ScrollSpy, null, [{
        key: "VERSION",
        get: function get() {
          return VERSION;
        }
      }, {
        key: "Default",
        get: function get() {
          return Default;
        }
      }]);

      return ScrollSpy;
    }();
    /**
     * ------------------------------------------------------------------------
     * Data Api implementation
     * ------------------------------------------------------------------------
     */


    $(window).on(Event.LOAD_DATA_API, function () {
      var scrollSpys = [].slice.call(document.querySelectorAll(Selector.DATA_SPY));
      var scrollSpysLength = scrollSpys.length;

      for (var i = scrollSpysLength; i--;) {
        var $spy = $(scrollSpys[i]);

        ScrollSpy._jQueryInterface.call($spy, $spy.data());
      }
    });
    /**
     * ------------------------------------------------------------------------
     * jQuery
     * ------------------------------------------------------------------------
     */

    $.fn[NAME] = ScrollSpy._jQueryInterface;
    $.fn[NAME].Constructor = ScrollSpy;

    $.fn[NAME].noConflict = function () {
      $.fn[NAME] = JQUERY_NO_CONFLICT;
      return ScrollSpy._jQueryInterface;
    };

    return ScrollSpy;

  }));

  });

  var Snackbar = /*#__PURE__*/function (_Ob1Component) {
    _inheritsLoose(Snackbar, _Ob1Component);

    function Snackbar(container, parameters) {
      var _this;

      _this = _Ob1Component.call(this, container, "Snackbar", parameters) || this;
      _this.snackbarTimer = 0;
      _this.displayDelay = 6000;
      _this.launchTime = null;
      return _this;
    }

    var _proto = Snackbar.prototype;

    _proto.pausedAnimation = function pausedAnimation() {
      var stopTime = new Date().getTime();
      clearTimeout(this.snackbarTimer);
      var passedTime = stopTime - this.launchTime;

      if (passedTime <= this.displayDelay) {
        this.displayDelay = this.displayDelay - passedTime;
      }
    };

    _proto.resetTimeout = function resetTimeout() {
      this.displayDelay = 6000;
    };

    _proto.startAnimation = function startAnimation() {
      var _this2 = this;

      this.launchTime = new Date().getTime();
      this.container.classList.add("show");
      this.snackbarTimer = setTimeout(function () {
        _this2.container.className = _this2.container.className.replace("show", "");

        _this2.resetTimeout();
      }, this.displayDelay + 150);
    };

    _proto.init = function init(container, parameters) {
      _Ob1Component.prototype.init.call(this, container, parameters);

      this.boundPausedAnimation = this.pausedAnimation.bind(this);
      this.boundStartAnimation = this.startAnimation.bind(this);
      this.container.addEventListener("mouseenter", this.boundPausedAnimation);
      this.container.addEventListener("focus", this.boundPausedAnimation);
      this.container.addEventListener("mouseleave", this.boundStartAnimation);
      this.container.addEventListener("blur", this.boundStartAnimation);
    };

    _proto.dispose = function dispose() {
      this.container.removeEventListener("mouseenter", this.boundPausedAnimation);
      this.container.removeEventListener("focus", this.boundPausedAnimation);
      this.container.removeEventListener("mouseleave", this.boundStartAnimation);
      this.container.removeEventListener("blur", this.boundStartAnimation);
      this.resetTimeout();
      clearTimeout(this.snackbarTimer);

      _Ob1Component.prototype.dispose.call(this);
    };

    return Snackbar;
  }(Ob1Component);

  window.Snackbar = Snackbar;

  var countriesRepository = [{
    country: "Afghanistan",
    icon: "flag-icon-af"
  }, {
    country: "Afrique du Sud",
    icon: "flag-icon-za"
  }, {
    country: "Åland, Îles",
    icon: "flag-icon-ax"
  }, {
    country: "Albanie",
    icon: "flag-icon-al"
  }, {
    country: "Algérie",
    icon: "flag-icon-dz"
  }, {
    country: "Allemagne",
    icon: "flag-icon-de"
  }, {
    country: "Andorre",
    icon: "flag-icon-ad"
  }, {
    country: "Angola",
    icon: "flag-icon-ao"
  }, {
    country: "Anguilla",
    icon: "flag-icon-ai"
  }, {
    country: "Antarctique",
    icon: "flag-icon-aq"
  }, {
    country: "Antigua et Barbuda",
    icon: "flag-icon-ag"
  }, {
    country: "Arabie Saoudite",
    icon: "flag-icon-sa"
  }, {
    country: "Argentine",
    icon: "flag-icon-ar"
  }, {
    country: "Arménie",
    icon: "flag-icon-am"
  }, {
    country: "Aruba",
    icon: "flag-icon-aw"
  }, {
    country: "Australie",
    icon: "flag-icon-au"
  }, {
    country: "Autriche",
    icon: "flag-icon-at"
  }, {
    country: "Azerbaïdjan",
    icon: "flag-icon-az"
  }, {
    country: "Bahamas",
    icon: "flag-icon-bs"
  }, {
    country: "Bahrein",
    icon: "flag-icon-bh"
  }, {
    country: "Bangladesh",
    icon: "flag-icon-bd"
  }, {
    country: "Barbade",
    icon: "flag-icon-bb"
  }, {
    country: "Bélarus",
    icon: "flag-icon-by"
  }, {
    country: "Belgique",
    icon: "flag-icon-be"
  }, {
    country: "Bélize",
    icon: "flag-icon-bz"
  }, {
    country: "Bénin",
    icon: "flag-icon-bj"
  }, {
    country: "Bermudes",
    icon: "flag-icon-bm"
  }, {
    country: "Bhoutan",
    icon: "flag-icon-bt"
  }, {
    country: "Bolivie (État plurinational de)",
    icon: "flag-icon-bo"
  }, {
    country: "Bonaire, Saint-Eustache et Saba",
    icon: "flag-icon-bq"
  }, {
    country: "Bosnie-Herzégovine",
    icon: "flag-icon-ba"
  }, {
    country: "Botswana",
    icon: "flag-icon-bw"
  }, {
    country: "Bouvet, Ile",
    icon: "flag-icon-bv"
  }, {
    country: "Brésil",
    icon: "flag-icon-br"
  }, {
    country: "Brunéi Darussalam",
    icon: "flag-icon-bn"
  }, {
    country: "Bulgarie",
    icon: "flag-icon-bg"
  }, {
    country: "Burkina Faso",
    icon: "flag-icon-bf"
  }, {
    country: "Burundi",
    icon: "flag-icon-bi"
  }, {
    country: "Cabo Verde",
    icon: "flag-icon-cv"
  }, {
    country: "Caïmans, Iles",
    icon: "flag-icon-ky"
  }, {
    country: "Cambodge",
    icon: "flag-icon-kh"
  }, {
    country: "Cameroun",
    icon: "flag-icon-cm"
  }, {
    country: "Canada",
    icon: "flag-icon-ca"
  }, {
    country: "Chili",
    icon: "flag-icon-cl"
  }, {
    country: "Chine",
    icon: "flag-icon-cn"
  }, {
    country: "Christmas, île",
    icon: "flag-icon-cx"
  }, {
    country: "Chypre",
    icon: "flag-icon-cy"
  }, {
    country: "Cocos/Keeling (Îles)",
    icon: "flag-icon-cc"
  }, {
    country: "Colombie",
    icon: "flag-icon-co"
  }, {
    country: "Comores",
    icon: "flag-icon-km"
  }, {
    country: "Congo",
    icon: "flag-icon-cg"
  }, {
    country: "Congo, République démocratique du",
    icon: "flag-icon-cd"
  }, {
    country: "Cook, Iles",
    icon: "flag-icon-ck"
  }, {
    country: "Corée, République de",
    icon: "flag-icon-kr"
  }, {
    country: "Corée, République populaire démocratique de",
    icon: "flag-icon-kp"
  }, {
    country: "Costa Rica",
    icon: "flag-icon-cr"
  }, {
    country: "Côte d'Ivoire",
    icon: "flag-icon-ci"
  }, {
    country: "Croatie",
    icon: "flag-icon-hr"
  }, {
    country: "Cuba",
    icon: "flag-icon-cu"
  }, {
    country: "Curaçao",
    icon: "flag-icon-cw"
  }, {
    country: "Danemark",
    icon: "flag-icon-dk"
  }, {
    country: "Djibouti",
    icon: "flag-icon-dj"
  }, {
    country: "Dominicaine, République",
    icon: "flag-icon-do"
  }, {
    country: "Dominique",
    icon: "flag-icon-dm"
  }, {
    country: "Egypte",
    icon: "flag-icon-eg"
  }, {
    country: "El Salvador",
    icon: "flag-icon-sv"
  }, {
    country: "Emirats arabes unis",
    icon: "flag-icon-ae"
  }, {
    country: "Equateur",
    icon: "flag-icon-ec"
  }, {
    country: "Erythrée",
    icon: "flag-icon-er"
  }, {
    country: "Espagne",
    icon: "flag-icon-es"
  }, {
    country: "Estonie",
    icon: "flag-icon-ee"
  }, {
    country: "Etats-Unis d'Amérique",
    icon: "flag-icon-us"
  }, {
    country: "Ethiopie",
    icon: "flag-icon-et"
  }, {
    country: "Falkland/Malouines (Îles)",
    icon: "flag-icon-fk"
  }, {
    country: "Féroé, îles",
    icon: "flag-icon-fo"
  }, {
    country: "Fidji",
    icon: "flag-icon-fj"
  }, {
    country: "Finlande",
    icon: "flag-icon-fi"
  }, {
    country: "France",
    icon: "flag-icon-fr"
  }, {
    country: "Gabon",
    icon: "flag-icon-ga"
  }, {
    country: "Gambie",
    icon: "flag-icon-gm"
  }, {
    country: "Géorgie",
    icon: "flag-icon-ge"
  }, {
    country: "Géorgie du sud et les îles Sandwich du sud",
    icon: "flag-icon-gs"
  }, {
    country: "Ghana",
    icon: "flag-icon-gh"
  }, {
    country: "Gibraltar",
    icon: "flag-icon-gi"
  }, {
    country: "Grèce",
    icon: "flag-icon-gr"
  }, {
    country: "Grenade",
    icon: "flag-icon-gd"
  }, {
    country: "Groenland",
    icon: "flag-icon-gl"
  }, {
    country: "Guadeloupe",
    icon: "flag-icon-gp"
  }, {
    country: "Guam",
    icon: "flag-icon-gu"
  }, {
    country: "Guatemala",
    icon: "flag-icon-gt"
  }, {
    country: "Guernesey",
    icon: "flag-icon-gg"
  }, {
    country: "Guinée",
    icon: "flag-icon-gn"
  }, {
    country: "Guinée-Bissau",
    icon: "flag-icon-gw"
  }, {
    country: "Guinée équatoriale",
    icon: "flag-icon-gq"
  }, {
    country: "Guyana",
    icon: "flag-icon-gy"
  }, {
    country: "Guyane française",
    icon: "flag-icon-gf"
  }, {
    country: "Haïti",
    icon: "flag-icon-ht"
  }, {
    country: "Heard, Ile et MacDonald, îles",
    icon: "flag-icon-hm"
  }, {
    country: "Honduras",
    icon: "flag-icon-hn"
  }, {
    country: "Hong Kong",
    icon: "flag-icon-hk"
  }, {
    country: "Hongrie",
    icon: "flag-icon-hu"
  }, {
    country: "Île de Man",
    icon: "flag-icon-im"
  }, {
    country: "Îles mineures éloignées des Etats-Unis",
    icon: "flag-icon-um"
  }, {
    country: "Îles vierges britanniques",
    icon: "flag-icon-vg"
  }, {
    country: "Îles vierges des Etats-Unis",
    icon: "flag-icon-vi"
  }, {
    country: "Inde",
    icon: "flag-icon-in"
  }, {
    country: "Indien (Territoire britannique de l'océan)",
    icon: "flag-icon-io"
  }, {
    country: "Indonésie",
    icon: "flag-icon-id"
  }, {
    country: "Iran, République islamique d'",
    icon: "flag-icon-ir"
  }, {
    country: "Iraq",
    icon: "flag-icon-iq"
  }, {
    country: "Irlande",
    icon: "flag-icon-ie"
  }, {
    country: "Islande",
    icon: "flag-icon-is"
  }, {
    country: "Israël",
    icon: "flag-icon-il"
  }, {
    country: "Italie",
    icon: "flag-icon-it"
  }, {
    country: "Jamaïque",
    icon: "flag-icon-jm"
  }, {
    country: "Japon",
    icon: "flag-icon-jp"
  }, {
    country: "Jersey",
    icon: "flag-icon-je"
  }, {
    country: "Jordanie",
    icon: "flag-icon-jo"
  }, {
    country: "Kazakhstan",
    icon: "flag-icon-kz"
  }, {
    country: "Kenya",
    icon: "flag-icon-ke"
  }, {
    country: "Kirghizistan",
    icon: "flag-icon-kg"
  }, {
    country: "Kiribati",
    icon: "flag-icon-ki"
  }, {
    country: "Koweït",
    icon: "flag-icon-kw"
  }, {
    country: "Lao, République démocratique populaire",
    icon: "flag-icon-la"
  }, {
    country: "Lesotho",
    icon: "flag-icon-ls"
  }, {
    country: "Lettonie",
    icon: "flag-icon-lv"
  }, {
    country: "Liban",
    icon: "flag-icon-lb"
  }, {
    country: "Libéria",
    icon: "flag-icon-lr"
  }, {
    country: "Libye",
    icon: "flag-icon-ly"
  }, {
    country: "Liechtenstein",
    icon: "flag-icon-li"
  }, {
    country: "Lituanie",
    icon: "flag-icon-lt"
  }, {
    country: "Luxembourg",
    icon: "flag-icon-lu"
  }, {
    country: "Macao",
    icon: "flag-icon-mo"
  }, {
    country: "Macédoine, l'ex-République yougoslave de",
    icon: "flag-icon-mk"
  }, {
    country: "Madagascar",
    icon: "flag-icon-mg"
  }, {
    country: "Malaisie",
    icon: "flag-icon-my"
  }, {
    country: "Malawi",
    icon: "flag-icon-mw"
  }, {
    country: "Maldives",
    icon: "flag-icon-mv"
  }, {
    country: "Mali",
    icon: "flag-icon-ml"
  }, {
    country: "Malte",
    icon: "flag-icon-mt"
  }, {
    country: "Mariannes du nord, Iles",
    icon: "flag-icon-mp"
  }, {
    country: "Maroc",
    icon: "flag-icon-ma"
  }, {
    country: "Marshall, Iles",
    icon: "flag-icon-mh"
  }, {
    country: "Martinique",
    icon: "flag-icon-mq"
  }, {
    country: "Maurice",
    icon: "flag-icon-mu"
  }, {
    country: "Mauritanie",
    icon: "flag-icon-mr"
  }, {
    country: "Mayotte",
    icon: "flag-icon-yt"
  }, {
    country: "Mexique",
    icon: "flag-icon-mx"
  }, {
    country: "Micronésie, Etats Fédérés de",
    icon: "flag-icon-fm"
  }, {
    country: "Moldova, République de",
    icon: "flag-icon-md"
  }, {
    country: "Monaco",
    icon: "flag-icon-mc"
  }, {
    country: "Mongolie",
    icon: "flag-icon-mn"
  }, {
    country: "Monténégro",
    icon: "flag-icon-me"
  }, {
    country: "Montserrat",
    icon: "flag-icon-ms"
  }, {
    country: "Mozambique",
    icon: "flag-icon-mz"
  }, {
    country: "Myanmar",
    icon: "flag-icon-mm"
  }, {
    country: "Namibie",
    icon: "flag-icon-na"
  }, {
    country: "Nauru",
    icon: "flag-icon-nr"
  }, {
    country: "Népal",
    icon: "flag-icon-np"
  }, {
    country: "Nicaragua",
    icon: "flag-icon-ni"
  }, {
    country: "Niger",
    icon: "flag-icon-ne"
  }, {
    country: "Nigéria",
    icon: "flag-icon-ng"
  }, {
    country: "Niue",
    icon: "flag-icon-nu"
  }, {
    country: "Norfolk, Ile",
    icon: "flag-icon-nf"
  }, {
    country: "Norvège",
    icon: "flag-icon-no"
  }, {
    country: "Nouvelle-Calédonie",
    icon: "flag-icon-nc"
  }, {
    country: "Nouvelle-Zélande",
    icon: "flag-icon-nz"
  }, {
    country: "Oman",
    icon: "flag-icon-om"
  }, {
    country: "Ouganda",
    icon: "flag-icon-ug"
  }, {
    country: "Ouzbékistan",
    icon: "flag-icon-uz"
  }, {
    country: "Pakistan",
    icon: "flag-icon-pk"
  }, {
    country: "Palaos",
    icon: "flag-icon-pw"
  }, {
    country: "Palestine, Etat de",
    icon: "flag-icon-ps"
  }, {
    country: "Panama",
    icon: "flag-icon-pa"
  }, {
    country: "Papouasie-Nouvelle-Guinée",
    icon: "flag-icon-pg"
  }, {
    country: "Paraguay",
    icon: "flag-icon-py"
  }, {
    country: "Pays-Bas",
    icon: "flag-icon-nl"
  }, {
    country: "Pérou",
    icon: "flag-icon-pe"
  }, {
    country: "Philippines",
    icon: "flag-icon-ph"
  }, {
    country: "Pitcairn",
    icon: "flag-icon-pn"
  }, {
    country: "Pologne",
    icon: "flag-icon-pl"
  }, {
    country: "Polynésie française",
    icon: "flag-icon-pf"
  }, {
    country: "Porto Rico",
    icon: "flag-icon-pr"
  }, {
    country: "Portugal",
    icon: "flag-icon-pt"
  }, {
    country: "Qatar",
    icon: "flag-icon-qa"
  }, {
    country: "République arabe syrienne",
    icon: "flag-icon-sy"
  }, {
    country: "République centrafricaine",
    icon: "flag-icon-cf"
  }, {
    country: "Réunion",
    icon: "flag-icon-re"
  }, {
    country: "Roumanie",
    icon: "flag-icon-ro"
  }, {
    country: "Royaume-Uni de Grande-Bretagne et d'Irlande du Nord",
    icon: "flag-icon-gb"
  }, {
    country: "Russie, Fédération de",
    icon: "flag-icon-ru"
  }, {
    country: "Rwanda",
    icon: "flag-icon-rw"
  }, {
    country: "Sahara occidental",
    icon: "flag-icon-eh"
  }, {
    country: "Saint-Barthélemy",
    icon: "flag-icon-bl"
  }, {
    country: "Saint-Kitts-et-Nevis",
    icon: "flag-icon-kn"
  }, {
    country: "Saint-Marin",
    icon: "flag-icon-sm"
  }, {
    country: "Saint-Martin (partie française)",
    icon: "flag-icon-mf"
  }, {
    country: "Saint-Martin (partie néerlandaise)",
    icon: "flag-icon-sx"
  }, {
    country: "Saint-Pierre-et-Miquelon",
    icon: "flag-icon-pm"
  }, {
    country: "Saint-Siège",
    icon: "flag-icon-va"
  }, {
    country: "Saint-Vincent-et-les-Grenadines",
    icon: "flag-icon-vc"
  }, {
    country: "Sainte-Hélène, Ascension et Tristan da Cunha",
    icon: "flag-icon-sh"
  }, {
    country: "Sainte-Lucie",
    icon: "flag-icon-lc"
  }, {
    country: "Salomon, Iles",
    icon: "flag-icon-sb"
  }, {
    country: "Samoa",
    icon: "flag-icon-ws"
  }, {
    country: "Samoa américaines",
    icon: "flag-icon-as"
  }, {
    country: "Sao Tomé-et-Principe",
    icon: "flag-icon-st"
  }, {
    country: "Sénégal",
    icon: "flag-icon-sn"
  }, {
    country: "Serbie",
    icon: "flag-icon-rs"
  }, {
    country: "Seychelles",
    icon: "flag-icon-sc"
  }, {
    country: "Sierra Leone",
    icon: "flag-icon-sl"
  }, {
    country: "Singapour",
    icon: "flag-icon-sg"
  }, {
    country: "Slovaquie",
    icon: "flag-icon-sk"
  }, {
    country: "Slovénie",
    icon: "flag-icon-si"
  }, {
    country: "Somalie",
    icon: "flag-icon-so"
  }, {
    country: "Soudan",
    icon: "flag-icon-sd"
  }, {
    country: "Soudan du Sud",
    icon: "flag-icon-ss"
  }, {
    country: "Sri Lanka",
    icon: "flag-icon-lk"
  }, {
    country: "Suède",
    icon: "flag-icon-se"
  }, {
    country: "Suisse",
    icon: "flag-icon-ch"
  }, {
    country: "Suriname",
    icon: "flag-icon-sr"
  }, {
    country: "Svalbard et île Jan Mayen",
    icon: "flag-icon-sj"
  }, {
    country: "Swaziland",
    icon: "flag-icon-sz"
  }, {
    country: "Tadjikistan",
    icon: "flag-icon-tj"
  }, {
    country: "Taïwan, Province de Chine",
    icon: "flag-icon-tw"
  }, {
    country: "Tanzanie, République unie de",
    icon: "flag-icon-tz"
  }, {
    country: "Tchad",
    icon: "flag-icon-td"
  }, {
    country: "Tchèque, République",
    icon: "flag-icon-cz"
  }, {
    country: "Terres australes françaises",
    icon: "flag-icon-tf"
  }, {
    country: "Thaïlande",
    icon: "flag-icon-th"
  }, {
    country: "Timor-Leste",
    icon: "flag-icon-tl"
  }, {
    country: "Togo",
    icon: "flag-icon-tg"
  }, {
    country: "Tokelau",
    icon: "flag-icon-tk"
  }, {
    country: "Tonga",
    icon: "flag-icon-to"
  }, {
    country: "Trinité-et-Tobago",
    icon: "flag-icon-tt"
  }, {
    country: "Tunisie",
    icon: "flag-icon-tn"
  }, {
    country: "Turkménistan",
    icon: "flag-icon-tm"
  }, {
    country: "Turks-et-Caïcos (Îles)",
    icon: "flag-icon-tc"
  }, {
    country: "Turquie",
    icon: "flag-icon-tr"
  }, {
    country: "Tuvalu",
    icon: "flag-icon-tv"
  }, {
    country: "Ukraine",
    icon: "flag-icon-ua"
  }, {
    country: "Uruguay",
    icon: "flag-icon-uy"
  }, {
    country: "Vanuatu",
    icon: "flag-icon-vu"
  }, {
    country: "Venezuela (République bolivarienne du)",
    icon: "flag-icon-ve"
  }, {
    country: "Viet Nam",
    icon: "flag-icon-vn"
  }, {
    country: "Wallis et Futuna",
    icon: "flag-icon-wf"
  }, {
    country: "Yémen",
    icon: "flag-icon-ye"
  }, {
    country: "Zambie",
    icon: "flag-icon-zm"
  }, {
    country: "Zimbabwe",
    icon: "flag-icon-zw"
  }];
  var accessibilityLabels = {
    nav: "Lorsque des résultats sont disponibles, utiliser les flèches haut et bas pour naviguer dans les propositions." + "Depuis un périphérique tactile, explorer en utilisant un balayage.",
    characters: "Merci de saisir un minimum de 3 caractères.",
    results: " résultats sont disponibles."
  };
  var searchFieldEventsListener = {
    KEYUP: "keyup",
    KEYDOWN: "keydown",
    CLICK: "click"
  };
  var searchFieldEventsCode = {
    BACKSPACE_CODE: "Backspace",
    DELETE_CODE: "Delete",
    SPACE: "Space",
    ENTER: "Enter",
    ESCAPE: "Escape",
    UP: "ArrowUp",
    DOWN: "ArrowDown",
    RIGHT: "ArrowRight",
    LEFT: "ArrowLeft",
    TAB: "Tab"
  };
  var searchFieldElements = {
    RESULT_LINE: "li",
    SPAN: "span"
  };
  var searchFieldClasses = {
    FIELD_SEARCH_INVALID: "is-invalid",
    FIELD_SEARCH_COUNTRY_SELECTED: "search-country-selected",
    RESULT_LINE: "result-line",
    RESULT_LINE_FOCUSED: "result-line-focused",
    BOLD: "font-weight-bold",
    FLAG_ICON: "flag-icon",
    DISPLAY_NONE: "d-none",
    DISPLAY_INLINE_BLOCK: "d-inline-block",
    MARGIN_RIGHT_1: "mr-1",
    FORM_CONTROL_HELP: "form-control-help"
  };
  var searchFieldSelectors = {
    FIELD_SEARCH_COUNTRY_SELECTED: "span.search-country-selected"
  };
  var searchFieldAttributes = {
    ROLE: "role",
    ROLE_BUTTON_VALUE: "button",
    ROLE_OPTION: "option",
    ARIA_POSINSET: "aria-posinset",
    ARIA_SETSIZE: "aria-setsize",
    ARIA_SELECTED: "aria-selected",
    TABINDEX: "tabindex",
    TABINDEX_ZERO_VALUE: "0",
    TABINDEX_NEGATIVE_VALUE: "-1"
  };
  var maxLinesNumber = 7;

  var SearchField = /*#__PURE__*/function (_Ob1Component) {
    _inheritsLoose(SearchField, _Ob1Component);

    function SearchField(container, parameters) {
      return _Ob1Component.call(this, container, "SearchField", parameters) || this;
    }

    var _proto = SearchField.prototype;

    _proto.init = function init(container, parameters) {
      this.container = container; // récupération des paramètres d'instanciation

      parameters = parameters || {};
      this.parameters = {};
      this.maxLinesNumber = 0;
      var repository = adressesRepository;
      var searchFieldId = this.container.dataset.searchfieldSearchfield;
      var searchFieldResultsId = this.container.dataset.searchfieldSearchfieldResults;
      var isCountrySearch = this.container.dataset.searchfieldIsCountrySearch; // on appelle la méthode d'initialisation d'Ob1Component (obligatoire)

      _Ob1Component.prototype.init.call(this, container, parameters); // Référentiel utilisé pour afficher les résultats


      this.repository = repository; // Nombre total de résultats

      this.repositoryLength = repository.length - 1; // Elément correspondant au champ de recherche

      this.searchField = document.getElementById(searchFieldId); // Elément correspondant à la liste de résultats, que l'on masque

      this.searchFieldResults = document.getElementById(searchFieldResultsId);
      this.displayResultsList(false); // Est ce une recherche de pays

      this.isCountrySearch = isCountrySearch;

      this._addEvents(); // ajout d'infos pour l'accessibilité


      this.searchField.setAttribute("aria-control", searchFieldId);
      this.searchField.setAttribute("role", "combobox");
      this.searchField.setAttribute("aria-expanded", "false");
      this.searchField.setAttribute("autocomplete", "off");
      this.searchField.setAttribute("aria-autocomplete", "list");
      this.accessibilitySr = this.searchField.parentNode.querySelector(".search-field-sr");
      this.accessibility = document.createElement("span");
      this.accessibilitySr.appendChild(this.accessibility);
      this.accessibility.innerHTML = accessibilityLabels.nav;
      this.accessibility.innerHTML += accessibilityLabels.characters;
      this.selectedResult = -1;
    }
    /**
     * Gestion des événements sur le composant
     * @private
     */
    ;

    _proto._addEvents = function _addEvents() {
      var _this = this;

      // On met un listener pour pouvoir raffraichir les résultats à chaque fois que la personne relache une touche du clavier
      this.boundRefreshSearchFieldResults = this.refreshSearchFieldResults.bind(this);
      this.searchField.addEventListener(searchFieldEventsListener.KEYUP, this.boundRefreshSearchFieldResults); // On met un listener pour pouvoir supprimer le drapeau présent dans le searchField lorsqu'un résultat a déjà été sélectionné

      this.boundSearchCountryFieldReinitilisation = this.searchCountryFieldReinitilisation.bind(this);
      this.searchField.addEventListener(searchFieldEventsListener.KEYDOWN, this.boundSearchCountryFieldReinitilisation); // On met un listener pour vérifier si l'utilisateur clique sur la croix du champs de recherche et effacer la liste des résultats

      this._onSearch = function (event) {
        _this.refreshSearchFieldResults(event);

        _this.selectedResult = -1;
      };

      this.searchField.addEventListener("search", this._onSearch);
    }
    /**
     * Décharge le composant
     */
    ;

    _proto.dispose = function dispose() {
      var _this2 = this;

      this.searchField.removeEventListener(searchFieldEventsListener.KEYUP, this.boundRefreshSearchFieldResults);
      this.searchField.removeEventListener(searchFieldEventsListener.KEYDOWN, this.boundSearchCountryFieldReinitilisation);
      this.searchField.removeEventListener("search", this._onSearch);
      var newResultLine = "";

      if (this.isCountrySearch === "true") {
        newResultLine = this.createNewCountryResultLine(lineToDisplay, lineIndex);
      } else {
        newResultLine = this.createNewResultLine(lineToDisplay, lineIndex);
      }

      newResultLine.removeEventListener(searchFieldEventsListener.CLICK, function () {
        return _this2.addSeletedResult(newResultLine);
      });
      newResultLine.removeEventListener(searchFieldEventsListener.KEYDOWN, this._onKeydown);
    }
    /**
     * Rafraîchit les résultats
     * @param {Event} event - événement qui déclenche le rafraîchissement des résultats
     */
    ;

    _proto.refreshSearchFieldResults = function refreshSearchFieldResults(event) {
      var _this3 = this;

      // On supprime les résultats affichés précédemment
      this.searchFieldResults.innerHTML = ""; // On efface le drapeau

      if (this.isCountrySearch === "true") {
        var searchFieldFlagElement = document.querySelector(searchFieldSelectors.FIELD_SEARCH_COUNTRY_SELECTED);

        if (searchFieldFlagElement !== null) {
          searchFieldFlagElement.remove();
          this.searchField.classList.remove(searchFieldClasses.FIELD_SEARCH_COUNTRY_SELECTED);
        }
      } // Il faut au moins 1 caractère renseigné dans le champ de recherche pour afficher des résultats


      if (this.searchField.value.length > 0) {
        // On filtre les résultats à afficher dans le cas d'une recherche de pays
        if (this.isCountrySearch === "true") {
          this.repository = this.getFilteredListOfCountries();
        } // On affiche le message d'erreur dans le cas où aucun résultat n'est à afficher
        // et on cache la liste de résultats


        if (this.repository.length > 0) {
          this.searchField.classList.remove(searchFieldClasses.FIELD_SEARCH_INVALID);
          this.displayResultsList(true);
        } else {
          this.searchField.classList.add(searchFieldClasses.FIELD_SEARCH_INVALID);
          this.displayResultsList(false);
        } // On affiche au maximum 7 résultats


        this.maxLinesNumber = Math.min(this.repository.length, maxLinesNumber); // On masque le bloc "Helper text"

        this.checkHelperText(true); // On ajoute les lignes de résultats

        this.repository.slice(0, this.maxLinesNumber).forEach(function (line, index) {
          _this3.addNewResultLine(line, index);
        }); // Ajout du nombre de résultats aux infos de l'accessibilité

        this.accessibility.innerHTML = this.maxLinesNumber + accessibilityLabels.results;
        this.searchField.setAttribute("aria-expanded", "true");
        this.navigateArrows(event);
      } else {
        // On affiche le bloc "Helper text" et on masque la liste de résultats
        this.checkHelperText(false);
        this.displayResultsList(false);
      }
    }
    /**
     * Actions sur les flèches haut et bas
     * @param {Event} event - événement qui déclenche la navigation par les flèches haut et bas
     */
    ;

    _proto.navigateArrows = function navigateArrows(event) {
      if (event.code === searchFieldEventsCode.UP) {
        event.preventDefault();

        if (this.selectedResult > -1) {
          this.selectedResult = this.selectedResult - 1;
        }

        this.focusOnProposition();
      }

      if (event.code === searchFieldEventsCode.DOWN && this.selectedResult < this.maxLinesNumber - 1) {
        event.preventDefault();
        this.selectedResult = this.selectedResult + 1;
        this.focusOnProposition();
      }
    }
    /**
     * Met le focus sur la ligne de résultat correspondant à la flèche clavier haut ou bas
     */
    ;

    _proto.focusOnProposition = function focusOnProposition() {
      this.searchFieldResultsLi = this.searchFieldResults.querySelectorAll(".result-line"); // on reinitialise tous les resultats

      for (var j = 0; j < this.searchFieldResultsLi.length; j++) {
        this.searchFieldResultsLi[j].classList.remove(searchFieldClasses.RESULT_LINE_FOCUSED);
        this.searchFieldResultsLi[j].setAttribute(searchFieldAttributes.ARIA_SELECTED, "false");
      } // on met à jour le focus sur le resultat choisit par l'utilisateur


      if (this.selectedResult < 0) {
        this.searchField.focus();
      } else if (this.selectedResult >= 0 && this.searchFieldResultsLi.length > 0) {
        this.searchFieldResultsLi[this.selectedResult].classList.add(searchFieldClasses.RESULT_LINE_FOCUSED);
        this.searchFieldResultsLi[this.selectedResult].setAttribute(searchFieldAttributes.ARIA_SELECTED, "true");
        this.searchFieldResultsLi[this.selectedResult].focus();
      }
    }
    /**
     * Ajoute une nouvelle ligne dans le champ de résultats
     * @param {*} lineToDisplay - Ligne de résultat à afficher
     * @param {*} lineIndex - Position de la ligne de résultat
     */
    ;

    _proto.addNewResultLine = function addNewResultLine(lineToDisplay, lineIndex) {
      var _this4 = this;

      var newResultLine = "";

      if (this.isCountrySearch === "true") {
        newResultLine = this.createNewCountryResultLine(lineToDisplay, lineIndex);
      } else {
        newResultLine = this.createNewResultLine(lineToDisplay, lineIndex);
      }

      this.searchFieldResults.appendChild(newResultLine); // On met des listners pour mettre à jour le champ de recherche avec la valeur sélectionnée (click souris + pression touches 'Entrée' ou 'Espace')

      newResultLine.addEventListener(searchFieldEventsListener.CLICK, function () {
        return _this4.addSeletedResult(newResultLine);
      });

      this._onKeydown = function (event) {
        // On regarde si utilisateur utilise touches : validation
        if (event.code === searchFieldEventsCode.SPACE || event.code === searchFieldEventsCode.ENTER) {
          _this4.addSeletedResult(newResultLine);

          _this4.searchField.focus();
        } // On regarde si utilisateur utilise touches : haut/bas


        _this4.navigateArrows(event); // On regarde si utilisateur utilise touches : droite/gauche


        if (event.code === searchFieldEventsCode.LEFT || event.code === searchFieldEventsCode.RIGHT) {
          // on reinitialise tous les resultats
          for (var j = 0; j < _this4.searchFieldResultsLi.length; j++) {
            _this4.searchFieldResultsLi[j].classList.remove(searchFieldClasses.RESULT_LINE_FOCUSED);

            _this4.searchFieldResultsLi[j].setAttribute(searchFieldAttributes.ARIA_SELECTED, "false");
          }

          _this4.searchField.focus();

          _this4.selectedResult = -1;
        } // On regarde si utilisateur utilise touches : echap


        if (event.code === searchFieldEventsCode.ESCAPE) {
          _this4.searchFieldResults.innerHTML = "";

          _this4.searchField.focus();

          _this4.selectedResult = -1;
        }
      };

      newResultLine.addEventListener(searchFieldEventsListener.KEYDOWN, this._onKeydown);
    }
    /**
     * Crée une nouvelle ligne de résultat pour une recherche basique
     * @param {string} lineToDisplay - Ligne de résultat à afficher
     * @param {*} lineIndex - Position de la ligne de résultat
     */
    ;

    _proto.createNewResultLine = function createNewResultLine(lineToDisplay, lineIndex) {
      var resultLine = this.initResultLine(lineIndex); // Création de l'élément contenant le début de la ligne de résultat

      var resultLineStart = this.initResultLineStart(lineToDisplay); // Création de l'élément contenant la fin de la ligne de résultat

      var resultLineEnd = this.initResultLineEnd(resultLineStart, lineToDisplay); // On construit la ligne de résultat

      resultLine.appendChild(resultLineStart);
      resultLine.appendChild(resultLineEnd);
      return resultLine;
    }
    /**
     * Crée une nouvelle ligne de résultat pour une recherche de pays
     * @param {object} lineToDisplay - Ligne de résultat à afficher
     * @param {*} lineIndex - Position de la ligne de résultat
     */
    ;

    _proto.createNewCountryResultLine = function createNewCountryResultLine(lineToDisplay, lineIndex) {
      var country = lineToDisplay.country;
      var countryIcon = lineToDisplay.icon;
      var resultLine = this.initResultLine(lineIndex); // Création de l'élement contenant le drapeau

      var resultLineFlag = this.initFlagElement(countryIcon); // Création de l'élément contenant le début de la ligne de résultat

      var resultLineStart = this.initResultLineStart(country); // Création de l'élément contenant la fin de la ligne de résultat

      var resultLineEnd = this.initResultLineEnd(resultLineStart, country); // On construit la ligne de résultat

      resultLine.appendChild(resultLineFlag);
      resultLine.appendChild(resultLineStart);
      resultLine.appendChild(resultLineEnd);
      return resultLine;
    }
    /**
     * Initialise une ligne de résultat
     * @param {*} lineIndex - Position de la ligne de résultat
     */
    ;

    _proto.initResultLine = function initResultLine(lineIndex) {
      var resultLine = document.createElement(searchFieldElements.RESULT_LINE);
      resultLine.classList.add(searchFieldClasses.RESULT_LINE);
      resultLine.setAttribute(searchFieldAttributes.TABINDEX, searchFieldAttributes.TABINDEX_NEGATIVE_VALUE);
      resultLine.setAttribute(searchFieldAttributes.ROLE, searchFieldAttributes.ROLE_OPTION);
      resultLine.setAttribute(searchFieldAttributes.ARIA_POSINSET, (lineIndex + 1).toString());
      resultLine.setAttribute(searchFieldAttributes.ARIA_SETSIZE, this.maxLinesNumber.toString());
      var ariaSelectedValue = false;

      if (this.searchField.value === resultLine.innerText) {
        ariaSelectedValue = true;
      }

      resultLine.setAttribute(searchFieldAttributes.ARIA_SELECTED, ariaSelectedValue);
      return resultLine;
    }
    /**
     * Initialise le début d'une ligne de résultat (partie correspondant à la valeur saisie dans le champ de recherche)
     * @param {string} lineToDisplay - Ligne de résultat à afficher
     */
    ;

    _proto.initResultLineStart = function initResultLineStart(lineToDisplay) {
      var resultLineStart = document.createElement(searchFieldElements.SPAN);
      resultLineStart.innerHTML = lineToDisplay.substring(0, this.searchField.value.length);
      return resultLineStart;
    }
    /**
     * Initialise la fin d'une ligne de résultat (on affiche en gras le reste de la ligne correspondant à la recherche)
     * @param {HTMLElement} resultLineStart - Début de la ligne de résultat
     * @param {string} lineToDisplay - Ligne de résultat à afficher
     */
    ;

    _proto.initResultLineEnd = function initResultLineEnd(resultLineStart, lineToDisplay) {
      var resultLineEnd = document.createElement(searchFieldElements.SPAN);
      resultLineEnd.innerHTML = lineToDisplay.substring(resultLineStart.innerHTML.length);
      resultLineEnd.classList.add(searchFieldClasses.BOLD);
      return resultLineEnd;
    }
    /**
     * Initialise un élément drapeau pour la recherche de pays
     * @param {string} countryIcon - Icône du pays
     */
    ;

    _proto.initFlagElement = function initFlagElement(countryIcon) {
      var flagElement = document.createElement(searchFieldElements.SPAN);
      flagElement.classList.add(searchFieldClasses.FLAG_ICON);
      flagElement.classList.add(countryIcon);
      flagElement.classList.add(searchFieldClasses.DISPLAY_INLINE_BLOCK);
      flagElement.classList.add(searchFieldClasses.MARGIN_RIGHT_1);
      return flagElement;
    }
    /**
     * Filtre les pays par rapport à la valeur saisie dans le champ de recherche
     */
    ;

    _proto.getFilteredListOfCountries = function getFilteredListOfCountries() {
      var _this5 = this;

      // hack IE pour supporter startsWith
      if (!String.prototype.startsWith) {
        String.prototype.startsWith = function (searchString, position) {
          position = position || 0;
          return this.indexOf(searchString, position) === position;
        };
      }

      return countriesRepository.filter(function (line) {
        return line.country.toUpperCase().substring(0, _this5.searchField.value.length).startsWith(_this5.searchField.value.toUpperCase());
      });
    }
    /**
     * Affiche ou cache l'élément 'Helper Text'
     * @param {boolean} hideHelperText - True si on veut cacher
     */
    ;

    _proto.checkHelperText = function checkHelperText(hideHelperText) {
      var searchFieldParent = this.searchFieldResults.parentElement;
      var searchFieldParentChildren = searchFieldParent.children;
      Array.from(searchFieldParentChildren).forEach(function (child) {
        if (child.classList.contains(searchFieldClasses.FORM_CONTROL_HELP)) {
          if (hideHelperText) {
            child.classList.add(searchFieldClasses.DISPLAY_NONE);
          } else {
            child.classList.remove(searchFieldClasses.DISPLAY_NONE);
          }
        }
      });
    }
    /**
     * Affiche ou masque la liste de résultats
     * @param {boolean} displayResults - true si on veut afficher la liste
     */
    ;

    _proto.displayResultsList = function displayResultsList(displayResults) {
      if (displayResults) {
        this.searchFieldResults.classList.remove(searchFieldClasses.DISPLAY_NONE);
      } else {
        this.searchFieldResults.classList.add(searchFieldClasses.DISPLAY_NONE);
      }
    }
    /**
     * Ajoute la valeur sélectionnée dans le champ de recherche
     * @param {HTMLElement} resultLine - Ligne de résultat
     */
    ;

    _proto.addSeletedResult = function addSeletedResult(resultLine) {
      this.searchField.value = resultLine.innerText; // On supprime les résultats affichés précédemment et on masque la liste

      this.searchFieldResults.innerHTML = "";
      this.displayResultsList(false); // on met à jour l'accessibilité

      this.searchField.setAttribute("aria-expanded", "false");

      if (this.isCountrySearch === "true") {
        // On affiche l'icône du drapeau à côté du pays sélectionné
        var iconElement = resultLine.firstChild;
        this.searchFieldResults.parentNode.insertBefore(iconElement, this.searchFieldResults);
        this.searchField.classList.add(searchFieldClasses.FIELD_SEARCH_COUNTRY_SELECTED);
        iconElement.classList.add(searchFieldClasses.FIELD_SEARCH_COUNTRY_SELECTED);
      }
    }
    /**
     * Supprime le drapeau ajouté dans le champ de recherche lors d'une première sélection de pays
     * @param {Event} event - événement qui déclenche la réinitialisation de la recherche par pays
     */
    ;

    _proto.searchCountryFieldReinitilisation = function searchCountryFieldReinitilisation(event) {
      if (this.isCountrySearch === "true" && (event.code === searchFieldEventsCode.BACKSPACE_CODE || event.code === searchFieldEventsCode.DELETE_CODE || event.code === "")) {
        var searchFieldFlagElement = document.querySelector(searchFieldSelectors.FIELD_SEARCH_COUNTRY_SELECTED);

        if (searchFieldFlagElement !== null) {
          searchFieldFlagElement.remove();
          this.searchField.classList.remove(searchFieldClasses.FIELD_SEARCH_COUNTRY_SELECTED);
        }
      }
    };

    return SearchField;
  }(Ob1Component); // rattachement au contexte window pour pouvoir l'utiliser en dehors du JS


  window.SearchField = SearchField;

  var tab = createCommonjsModule(function (module, exports) {
  /*!
    * Boosted v4.3.1 (https://boosted.orange.com)
    * Copyright 2014-2019 The Boosted Authors
    * Copyright 2014-2019 Orange
    * Licensed under MIT (https://github.com/orange-opensource/orange-boosted-bootstrap/blob/master/LICENSE)
    * This a fork of Bootstrap : Initial license below
    * Bootstrap tab.js v4.3.1 (https://boosted.orange.com)
    * Copyright 2011-2019 The Boosted Authors (https://github.com/Orange-OpenSource/Orange-Boosted-Bootstrap/graphs/contributors)
    * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
    */
  (function (global, factory) {
     module.exports = factory(jquery, util) ;
  }(commonjsGlobal, function ($, Util) {
    $ = $ && $.hasOwnProperty('default') ? $['default'] : $;
    Util = Util && Util.hasOwnProperty('default') ? Util['default'] : Util;

    function _defineProperties(target, props) {
      for (var i = 0; i < props.length; i++) {
        var descriptor = props[i];
        descriptor.enumerable = descriptor.enumerable || false;
        descriptor.configurable = true;
        if ("value" in descriptor) descriptor.writable = true;
        Object.defineProperty(target, descriptor.key, descriptor);
      }
    }

    function _createClass(Constructor, protoProps, staticProps) {
      if (protoProps) _defineProperties(Constructor.prototype, protoProps);
      if (staticProps) _defineProperties(Constructor, staticProps);
      return Constructor;
    }

    /**
     * ------------------------------------------------------------------------
     * Constants
     * ------------------------------------------------------------------------
     */

    var NAME = 'tab';
    var VERSION = '4.3.1';
    var DATA_KEY = 'bs.tab';
    var EVENT_KEY = "." + DATA_KEY;
    var DATA_API_KEY = '.data-api';
    var JQUERY_NO_CONFLICT = $.fn[NAME]; // boosted mod

    var ARROW_LEFT_KEYCODE = 37; // KeyboardEvent.which value for left arrow key

    var ARROW_UP_KEYCODE = 38; // KeyboardEvent.which value for up arrow key

    var ARROW_RIGHT_KEYCODE = 39; // KeyboardEvent.which value for right arrow key

    var ARROW_DOWN_KEYCODE = 40; // KeyboardEvent.which value for down arrow key

    var REGEXP_KEYDOWN = new RegExp(ARROW_LEFT_KEYCODE + "|" + ARROW_UP_KEYCODE + "|" + ARROW_RIGHT_KEYCODE + "|" + ARROW_DOWN_KEYCODE); // end mod

    var Event = {
      HIDE: "hide" + EVENT_KEY,
      HIDDEN: "hidden" + EVENT_KEY,
      SHOW: "show" + EVENT_KEY,
      SHOWN: "shown" + EVENT_KEY,
      CLICK_DATA_API: "click" + EVENT_KEY + DATA_API_KEY,
      KEYDOWN_DATA_API: "keydown" + EVENT_KEY + DATA_API_KEY // boosted mod

    };
    var ClassName = {
      DROPDOWN_MENU: 'dropdown-menu',
      ACTIVE: 'active',
      DISABLED: 'disabled',
      FADE: 'fade',
      SHOW: 'show'
    };
    var Selector = {
      DROPDOWN: '.dropdown',
      NAV_LIST_GROUP: '.nav, .list-group',
      ACTIVE: '.active',
      ACTIVE_UL: '> li > .active',
      DATA_TOGGLE: '[data-toggle="tab"], [data-toggle="pill"], [data-toggle="list"]',
      DROPDOWN_TOGGLE: '.dropdown-toggle',
      DROPDOWN_ACTIVE_CHILD: '> .dropdown-menu .active'
      /**
       * ------------------------------------------------------------------------
       * Class Definition
       * ------------------------------------------------------------------------
       */

    };

    var Tab =
    /*#__PURE__*/
    function () {
      function Tab(element) {
        this._element = element;

        this._addAccessibility(); // Boosted mod

      } // Getters


      var _proto = Tab.prototype;

      // Public
      _proto.show = function show() {
        var _this = this;

        if (this._element.parentNode && this._element.parentNode.nodeType === Node.ELEMENT_NODE && $(this._element).hasClass(ClassName.ACTIVE) || $(this._element).hasClass(ClassName.DISABLED)) {
          return;
        }

        var target;
        var previous;
        var listElement = $(this._element).closest(Selector.NAV_LIST_GROUP)[0];
        var selector = Util.getSelectorFromElement(this._element);

        if (listElement) {
          var itemSelector = listElement.nodeName === 'UL' || listElement.nodeName === 'OL' ? Selector.ACTIVE_UL : Selector.ACTIVE;
          previous = $.makeArray($(listElement).find(itemSelector));
          previous = previous[previous.length - 1];
        }

        var hideEvent = $.Event(Event.HIDE, {
          relatedTarget: this._element
        });
        var showEvent = $.Event(Event.SHOW, {
          relatedTarget: previous
        });

        if (previous) {
          $(previous).trigger(hideEvent);
        }

        $(this._element).trigger(showEvent);

        if (showEvent.isDefaultPrevented() || hideEvent.isDefaultPrevented()) {
          return;
        }

        if (selector) {
          target = document.querySelector(selector);
        }

        this._activate(this._element, listElement);

        var complete = function complete() {
          var hiddenEvent = $.Event(Event.HIDDEN, {
            relatedTarget: _this._element
          });
          var shownEvent = $.Event(Event.SHOWN, {
            relatedTarget: previous
          });
          $(previous).trigger(hiddenEvent);
          $(_this._element).trigger(shownEvent);
        };

        if (target) {
          this._activate(target, target.parentNode, complete);
        } else {
          complete();
        }
      };

      _proto.dispose = function dispose() {
        $.removeData(this._element, DATA_KEY);
        this._element = null;
      } // Private
      ;

      _proto._activate = function _activate(element, container, callback) {
        var _this2 = this;

        var activeElements = container && (container.nodeName === 'UL' || container.nodeName === 'OL') ? $(container).find(Selector.ACTIVE_UL) : $(container).children(Selector.ACTIVE);
        var active = activeElements[0];
        var isTransitioning = callback && active && $(active).hasClass(ClassName.FADE);

        var complete = function complete() {
          return _this2._transitionComplete(element, active, callback);
        }; // Boosted mod


        $(container).find('.nav-link:not(.dropdown-toggle)').attr({
          tabIndex: '-1',
          'aria-selected': false
        });
        $(container).find('.tab-pane').attr({
          'aria-hidden': true,
          tabIndex: '-1'
        }); // end mod

        if (active && isTransitioning) {
          var transitionDuration = Util.getTransitionDurationFromElement(active);
          $(active).removeClass(ClassName.SHOW).one(Util.TRANSITION_END, complete).emulateTransitionEnd(transitionDuration);
        } else {
          complete();
        }
      };

      _proto._transitionComplete = function _transitionComplete(element, active, callback) {
        if (active) {
          $(active).removeClass(ClassName.ACTIVE);
          var dropdownChild = $(active.parentNode).find(Selector.DROPDOWN_ACTIVE_CHILD)[0];

          if (dropdownChild) {
            $(dropdownChild).removeClass(ClassName.ACTIVE);
          }

          if (active.getAttribute('role') === 'tab') {
            active.setAttribute('aria-selected', false);
          }
        }

        $(element).addClass(ClassName.ACTIVE);

        if (element.getAttribute('role') === 'tab') {
          element.setAttribute('aria-selected', true);
        } // Boosted mod


        $(element).filter('.nav-link:not(.dropdown-toggle).active').attr({
          tabIndex: '0',
          'aria-selected': true
        });
        $(element).filter('.tab-pane.active').attr({
          'aria-hidden': false,
          tabIndex: '0'
        }); // end mod

        Util.reflow(element);

        if (element.classList.contains(ClassName.FADE)) {
          element.classList.add(ClassName.SHOW);
        }

        if (element.parentNode && $(element.parentNode).hasClass(ClassName.DROPDOWN_MENU)) {
          var dropdownElement = $(element).closest(Selector.DROPDOWN)[0];

          if (dropdownElement) {
            var dropdownToggleList = [].slice.call(dropdownElement.querySelectorAll(Selector.DROPDOWN_TOGGLE));
            $(dropdownToggleList).addClass(ClassName.ACTIVE);
          }

          element.setAttribute('aria-expanded', true);
        }

        if (callback) {
          callback();
        }
      } // Boosted mod
      ;

      _proto._addAccessibility = function _addAccessibility() {
        var $tab = $(this._element);
        var $tabpanel = $($tab.attr('href'));
        var $tablist = $tab.closest(Selector.NAV_LIST_GROUP);
        var tabId = $tab.attr('id') || Util.getUID(NAME);
        $tab.attr('id', tabId);

        if ($tabpanel) {
          $tab.attr('role', 'tab');
          $tablist.attr('role', 'tablist'); // $li.attr('role', 'presentation')
        }

        if ($tab.hasClass(ClassName.ACTIVE)) {
          $tab.attr({
            tabIndex: '0',
            'aria-selected': 'true'
          });

          if ($tab.attr('href')) {
            $tab.attr('aria-controls', $tab.attr('href').substr(1));
          }

          $tabpanel.attr({
            role: 'tabpanel',
            tabIndex: '0',
            'aria-hidden': 'false',
            'aria-labelledby': tabId
          });
        } else {
          $tab.attr({
            tabIndex: '-1',
            'aria-selected': 'false'
          });

          if ($tab.attr('href')) {
            $tab.attr('aria-controls', $tab.attr('href').substr(1));
          }

          $tabpanel.attr({
            role: 'tabpanel',
            tabIndex: '-1',
            'aria-hidden': 'true',
            'aria-labelledby': tabId
          });
        }
      } // end mod
      // Static
      // Boosted mod
      ;

      Tab._dataApiKeydownHandler = function _dataApiKeydownHandler(e) {
        var $this = $(this);
        var Items = $this.closest('ul[role=tablist] ').find('[role=tab]:visible');
        var k = e.which || e.keyCode;
        var index = 0;
        index = Items.index(Items.filter(':focus'));

        if (k === ARROW_UP_KEYCODE || k === ARROW_LEFT_KEYCODE) {
          index--;
        } // up & left


        if (k === ARROW_RIGHT_KEYCODE || k === ARROW_DOWN_KEYCODE) {
          index++;
        } // down & right


        if (index < 0) {
          index = Items.length - 1;
        }

        if (index === Items.length) {
          index = 0;
        }

        var nextTab = Items.eq(index);

        if (nextTab.attr('role') === 'tab') {
          nextTab.tab('show').trigger('focus');
        }

        e.preventDefault();
        e.stopPropagation();
      } // end mod
      ;

      Tab._jQueryInterface = function _jQueryInterface(config) {
        return this.each(function () {
          var $this = $(this);
          var data = $this.data(DATA_KEY);

          if (!data) {
            data = new Tab(this);
            $this.data(DATA_KEY, data);
          } // Boosted mod


          if (/init/.test(config)) {
            return;
          } // end mod


          if (typeof config === 'string') {
            if (typeof data[config] === 'undefined') {
              throw new TypeError("No method named \"" + config + "\"");
            }

            data[config]();
          }
        });
      };

      _createClass(Tab, null, [{
        key: "VERSION",
        get: function get() {
          return VERSION;
        }
      }]);

      return Tab;
    }();
    /**
     * ------------------------------------------------------------------------
     * Data Api implementation
     * ------------------------------------------------------------------------
     */


    $(document).on(Event.CLICK_DATA_API, Selector.DATA_TOGGLE, function (event) {
      event.preventDefault();

      Tab._jQueryInterface.call($(this), 'show');
    }) // Boosted mod
    .on(Event.KEYDOWN_DATA_API, Selector.DATA_TOGGLE, function (event) {
      if (!REGEXP_KEYDOWN.test(event.which)) {
        return;
      }

      event.preventDefault();

      Tab._dataApiKeydownHandler.call($(this), event);
    }).on('DOMContentLoaded', function () {
      Tab._jQueryInterface.call($(Selector.DATA_TOGGLE), 'init');
    }); // end mod

    /**
     * ------------------------------------------------------------------------
     * jQuery
     * ------------------------------------------------------------------------
     */

    $.fn[NAME] = Tab._jQueryInterface;
    $.fn[NAME].Constructor = Tab;

    $.fn[NAME].noConflict = function () {
      $.fn[NAME] = JQUERY_NO_CONFLICT;
      return Tab._jQueryInterface;
    };

    return Tab;

  }));

  });

  var toast = createCommonjsModule(function (module, exports) {
  /*!
    * Boosted v4.3.1 (https://boosted.orange.com)
    * Copyright 2014-2019 The Boosted Authors
    * Copyright 2014-2019 Orange
    * Licensed under MIT (https://github.com/orange-opensource/orange-boosted-bootstrap/blob/master/LICENSE)
    * This a fork of Bootstrap : Initial license below
    * Bootstrap toast.js v4.3.1 (https://boosted.orange.com)
    * Copyright 2011-2019 The Boosted Authors (https://github.com/Orange-OpenSource/Orange-Boosted-Bootstrap/graphs/contributors)
    * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
    */
  (function (global, factory) {
     module.exports = factory(jquery, util) ;
  }(commonjsGlobal, function ($, Util) {
    $ = $ && $.hasOwnProperty('default') ? $['default'] : $;
    Util = Util && Util.hasOwnProperty('default') ? Util['default'] : Util;

    function _defineProperties(target, props) {
      for (var i = 0; i < props.length; i++) {
        var descriptor = props[i];
        descriptor.enumerable = descriptor.enumerable || false;
        descriptor.configurable = true;
        if ("value" in descriptor) descriptor.writable = true;
        Object.defineProperty(target, descriptor.key, descriptor);
      }
    }

    function _createClass(Constructor, protoProps, staticProps) {
      if (protoProps) _defineProperties(Constructor.prototype, protoProps);
      if (staticProps) _defineProperties(Constructor, staticProps);
      return Constructor;
    }

    function _defineProperty(obj, key, value) {
      if (key in obj) {
        Object.defineProperty(obj, key, {
          value: value,
          enumerable: true,
          configurable: true,
          writable: true
        });
      } else {
        obj[key] = value;
      }

      return obj;
    }

    function _objectSpread(target) {
      for (var i = 1; i < arguments.length; i++) {
        var source = arguments[i] != null ? arguments[i] : {};
        var ownKeys = Object.keys(source);

        if (typeof Object.getOwnPropertySymbols === 'function') {
          ownKeys = ownKeys.concat(Object.getOwnPropertySymbols(source).filter(function (sym) {
            return Object.getOwnPropertyDescriptor(source, sym).enumerable;
          }));
        }

        ownKeys.forEach(function (key) {
          _defineProperty(target, key, source[key]);
        });
      }

      return target;
    }

    /**
     * ------------------------------------------------------------------------
     * Constants
     * ------------------------------------------------------------------------
     */

    var NAME = 'toast';
    var VERSION = '4.3.1';
    var DATA_KEY = 'bs.toast';
    var EVENT_KEY = "." + DATA_KEY;
    var JQUERY_NO_CONFLICT = $.fn[NAME];
    var Event = {
      CLICK_DISMISS: "click.dismiss" + EVENT_KEY,
      HIDE: "hide" + EVENT_KEY,
      HIDDEN: "hidden" + EVENT_KEY,
      SHOW: "show" + EVENT_KEY,
      SHOWN: "shown" + EVENT_KEY
    };
    var ClassName = {
      FADE: 'fade',
      HIDE: 'hide',
      SHOW: 'show',
      SHOWING: 'showing'
    };
    var DefaultType = {
      animation: 'boolean',
      autohide: 'boolean',
      delay: 'number'
    };
    var Default = {
      animation: true,
      autohide: true,
      delay: 500
    };
    var Selector = {
      DATA_DISMISS: '[data-dismiss="toast"]'
      /**
       * ------------------------------------------------------------------------
       * Class Definition
       * ------------------------------------------------------------------------
       */

    };

    var Toast =
    /*#__PURE__*/
    function () {
      function Toast(element, config) {
        this._element = element;
        this._config = this._getConfig(config);
        this._timeout = null;

        this._setListeners();
      } // Getters


      var _proto = Toast.prototype;

      // Public
      _proto.show = function show() {
        var _this = this;

        $(this._element).trigger(Event.SHOW);

        if (this._config.animation) {
          this._element.classList.add(ClassName.FADE);
        }

        var complete = function complete() {
          _this._element.classList.remove(ClassName.SHOWING);

          _this._element.classList.add(ClassName.SHOW);

          $(_this._element).trigger(Event.SHOWN);

          if (_this._config.autohide) {
            _this.hide();
          }
        };

        this._element.classList.remove(ClassName.HIDE);

        this._element.classList.add(ClassName.SHOWING);

        if (this._config.animation) {
          var transitionDuration = Util.getTransitionDurationFromElement(this._element);
          $(this._element).one(Util.TRANSITION_END, complete).emulateTransitionEnd(transitionDuration);
        } else {
          complete();
        }
      };

      _proto.hide = function hide(withoutTimeout) {
        var _this2 = this;

        if (!this._element.classList.contains(ClassName.SHOW)) {
          return;
        }

        $(this._element).trigger(Event.HIDE);

        if (withoutTimeout) {
          this._close();
        } else {
          this._timeout = setTimeout(function () {
            _this2._close();
          }, this._config.delay);
        }
      };

      _proto.dispose = function dispose() {
        clearTimeout(this._timeout);
        this._timeout = null;

        if (this._element.classList.contains(ClassName.SHOW)) {
          this._element.classList.remove(ClassName.SHOW);
        }

        $(this._element).off(Event.CLICK_DISMISS);
        $.removeData(this._element, DATA_KEY);
        this._element = null;
        this._config = null;
      } // Private
      ;

      _proto._getConfig = function _getConfig(config) {
        config = _objectSpread({}, Default, $(this._element).data(), typeof config === 'object' && config ? config : {});
        Util.typeCheckConfig(NAME, config, this.constructor.DefaultType);
        return config;
      };

      _proto._setListeners = function _setListeners() {
        var _this3 = this;

        $(this._element).on(Event.CLICK_DISMISS, Selector.DATA_DISMISS, function () {
          return _this3.hide(true);
        });
      };

      _proto._close = function _close() {
        var _this4 = this;

        var complete = function complete() {
          _this4._element.classList.add(ClassName.HIDE);

          $(_this4._element).trigger(Event.HIDDEN);
        };

        this._element.classList.remove(ClassName.SHOW);

        if (this._config.animation) {
          var transitionDuration = Util.getTransitionDurationFromElement(this._element);
          $(this._element).one(Util.TRANSITION_END, complete).emulateTransitionEnd(transitionDuration);
        } else {
          complete();
        }
      } // Static
      ;

      Toast._jQueryInterface = function _jQueryInterface(config) {
        return this.each(function () {
          var $element = $(this);
          var data = $element.data(DATA_KEY);

          var _config = typeof config === 'object' && config;

          if (!data) {
            data = new Toast(this, _config);
            $element.data(DATA_KEY, data);
          }

          if (typeof config === 'string') {
            if (typeof data[config] === 'undefined') {
              throw new TypeError("No method named \"" + config + "\"");
            }

            data[config](this);
          }
        });
      };

      _createClass(Toast, null, [{
        key: "VERSION",
        get: function get() {
          return VERSION;
        }
      }, {
        key: "DefaultType",
        get: function get() {
          return DefaultType;
        }
      }, {
        key: "Default",
        get: function get() {
          return Default;
        }
      }]);

      return Toast;
    }();
    /**
     * ------------------------------------------------------------------------
     * jQuery
     * ------------------------------------------------------------------------
     */


    $.fn[NAME] = Toast._jQueryInterface;
    $.fn[NAME].Constructor = Toast;

    $.fn[NAME].noConflict = function () {
      $.fn[NAME] = JQUERY_NO_CONFLICT;
      return Toast._jQueryInterface;
    };

    return Toast;

  }));

  });

  (function(){(function(){function e(a){for(var b=[];a=a.parentNode||a.host||a.defaultView;)b.push(a);return b}function f(a){return function(b){var c="undefined"!==typeof b.getAttribute?b.getAttribute("class")||"":void 0;"undefined"!==typeof c&&-1===c.indexOf(a)&&b.setAttribute("class",c.concat(" ",a).trim());}}function g(a){return function(b){var c="undefined"!==typeof b.getAttribute?b.getAttribute("class")||"":void 0;if(c){var d=c.indexOf(a);0<=d&&(0===d||0<=h.indexOf(c.charAt(d-1)))&&
  (c=c.replace(a,"").trim(),""===c?b.removeAttribute("class"):b.setAttribute("class",c));}}}function k(){var a=function(b){function a(){d=!1;"blur"===b.type&&Array.prototype.slice.call(e(b.target)).forEach(g("focus-within"));"focus"===b.type&&Array.prototype.slice.call(e(b.target)).forEach(f("focus-within"));}if(!d){window.requestAnimationFrame(a);var d=!0;}};document.addEventListener("focus",a,!0);document.addEventListener("blur",a,!0);f("js-focus-within")(document.body);return !0}var h=["\n","\t"," ",
  "\r"];try{return "undefined"!==typeof window&&!document.querySelector(":focus-within")}catch(a){return k()}})();})();

  !function(r){function n(e){if(t[e])return t[e].exports;var o=t[e]={i:e,l:!1,exports:{}};return r[e].call(o.exports,o,o.exports,n),o.l=!0,o.exports}var t={};n.m=r,n.c=t,n.d=function(r,t,e){n.o(r,t)||Object.defineProperty(r,t,{configurable:!1,enumerable:!0,get:e});},n.n=function(r){var t=r&&r.__esModule?function(){return r.default}:function(){return r};return n.d(t,"a",t),t},n.o=function(r,n){return Object.prototype.hasOwnProperty.call(r,n)},n.p="",n(n.s=0);}([function(r,n){Array.from||(Array.from=function(){var r=Object.prototype.toString,n=function(n){return "function"==typeof n||"[object Function]"===r.call(n)},t=function(r){var n=Number(r);return isNaN(n)?0:0!==n&&isFinite(n)?(n>0?1:-1)*Math.floor(Math.abs(n)):n},e=Math.pow(2,53)-1,o=function(r){var n=t(r);return Math.min(Math.max(n,0),e)};return function(r){var t=this,e=Object(r);if(null==r)throw new TypeError("Array.from requires an array-like object - not null or undefined");var u,i=arguments.length>1?arguments[1]:void 0;if(void 0!==i){if(!n(i))throw new TypeError("Array.from: when provided, the second argument must be a function");arguments.length>2&&(u=arguments[2]);}for(var a,c=o(e.length),f=n(t)?Object(new t(c)):new Array(c),l=0;l<c;)a=e[l],f[l]=i?void 0===u?i(a,l):i.call(u,a,l):a,l+=1;return f.length=c,f}}());}]);

  if (!Element.prototype.matches) {
      Element.prototype.matches = Element.prototype.msMatchesSelector || Element.prototype.webkitMatchesSelector;
  }

  if (!Element.prototype.closest) {
      Element.prototype.closest = function (s) {
          var el = this;

          do {
              if (el.matches(s)) return el;
              el = el.parentElement || el.parentNode;
          } while (el !== null && el.nodeType === 1);
          return null;
      };
  }

  !function(e,t){"object"==typeof exports&&"undefined"!=typeof module?t():"function"==typeof define&&define.amd?define(t):t();}(0,function(){function e(e){var t=!0,n=!1,o=null,d={text:!0,search:!0,url:!0,tel:!0,email:!0,password:!0,number:!0,date:!0,month:!0,week:!0,time:!0,datetime:!0,"datetime-local":!0};function i(e){return !!(e&&e!==document&&"HTML"!==e.nodeName&&"BODY"!==e.nodeName&&"classList"in e&&"contains"in e.classList)}function s(e){e.classList.contains("focus-visible")||(e.classList.add("focus-visible"),e.setAttribute("data-focus-visible-added",""));}function u(e){t=!1;}function a(){document.addEventListener("mousemove",c),document.addEventListener("mousedown",c),document.addEventListener("mouseup",c),document.addEventListener("pointermove",c),document.addEventListener("pointerdown",c),document.addEventListener("pointerup",c),document.addEventListener("touchmove",c),document.addEventListener("touchstart",c),document.addEventListener("touchend",c);}function c(e){e.target.nodeName&&"html"===e.target.nodeName.toLowerCase()||(t=!1,document.removeEventListener("mousemove",c),document.removeEventListener("mousedown",c),document.removeEventListener("mouseup",c),document.removeEventListener("pointermove",c),document.removeEventListener("pointerdown",c),document.removeEventListener("pointerup",c),document.removeEventListener("touchmove",c),document.removeEventListener("touchstart",c),document.removeEventListener("touchend",c));}document.addEventListener("keydown",function(n){n.metaKey||n.altKey||n.ctrlKey||(i(e.activeElement)&&s(e.activeElement),t=!0);},!0),document.addEventListener("mousedown",u,!0),document.addEventListener("pointerdown",u,!0),document.addEventListener("touchstart",u,!0),document.addEventListener("visibilitychange",function(e){"hidden"===document.visibilityState&&(n&&(t=!0),a());},!0),a(),e.addEventListener("focus",function(e){var n,o,u;i(e.target)&&(t||(n=e.target,o=n.type,"INPUT"===(u=n.tagName)&&d[o]&&!n.readOnly||"TEXTAREA"===u&&!n.readOnly||n.isContentEditable))&&s(e.target);},!0),e.addEventListener("blur",function(e){var t;i(e.target)&&(e.target.classList.contains("focus-visible")||e.target.hasAttribute("data-focus-visible-added"))&&(n=!0,window.clearTimeout(o),o=window.setTimeout(function(){n=!1;},100),(t=e.target).hasAttribute("data-focus-visible-added")&&(t.classList.remove("focus-visible"),t.removeAttribute("data-focus-visible-added")));},!0),e.nodeType===Node.DOCUMENT_FRAGMENT_NODE&&e.host?e.host.setAttribute("data-js-focus-visible",""):e.nodeType===Node.DOCUMENT_NODE&&(document.documentElement.classList.add("js-focus-visible"),document.documentElement.setAttribute("data-js-focus-visible",""));}if("undefined"!=typeof window&&"undefined"!=typeof document){var t;window.applyFocusVisiblePolyfill=e;try{t=new CustomEvent("focus-visible-polyfill-ready");}catch(e){(t=document.createEvent("CustomEvent")).initCustomEvent("focus-visible-polyfill-ready",!1,!1,{});}window.dispatchEvent(t);}"undefined"!=typeof document&&e(document);});

  exports.Accordion = Accordion;
  exports.Alert = alert;
  exports.BoxRadioList = BoxRadioList;
  exports.Breadcrumb = Breadcrumb;
  exports.Button = button;
  exports.Carrousel = Carrousel;
  exports.Collapse = collapse;
  exports.DatePicker = DatePicker;
  exports.DateTimePicker = DateTimePicker;
  exports.DropdownComponent = DropdownComponent;
  exports.DropdownSelect = DropdownSelect;
  exports.FilterChipsbar = FilterChipsBar;
  exports.FormControlClear = FormControlClear;
  exports.FormControlEmpty = FormControlEmpty;
  exports.MegaMenu = megamenu;
  exports.Modal = modal;
  exports.Navbar = navbar;
  exports.OB1Common = ob1Common;
  exports.Otab = otab;
  exports.PageMenu = PageMenu;
  exports.Popover = popover;
  exports.Price = Price;
  exports.PriorityNav = prioritynav;
  exports.ProgressIndicators = index;
  exports.PromotionalCode = PromotionalCode;
  exports.ScrollUp = scrollup;
  exports.Scrollspy = scrollspy;
  exports.SearchField = SearchField;
  exports.SnackBar = Snackbar;
  exports.Tab = tab;
  exports.Toast = toast;
  exports.Tooltip = tooltip;
  exports.Util = util;

  Object.defineProperty(exports, '__esModule', { value: true });

})));
//# sourceMappingURL=ob1.js.map
