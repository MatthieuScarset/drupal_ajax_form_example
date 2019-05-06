//20151110
// Objet utilisateur
var loadACNow = typeof(window.loadAC) == "undefined";
if ( loadACNow )
{
	window.loadAC = 1;
function SynSuggests() {
	this.AddInput = AddInput;
	this.setChargementImmediat = setChargementImmediat;
	this.setChargementSurDelai = setChargementSurDelai;
	this.setChargementSurFocus = setChargementSurFocus;
	this.setChargementSurTouche = setChargementSurTouche;
	this.Start = Start;
}

// Fonction gestion chargement

function AddInput(Elt, className) {
	if ( Elt ) {
		GestionDom.debug("Ajout d'un element - id:"+(typeof Elt.id != "undefined"?Elt.id:"")+" - class:"+(typeof className != "undefined"?className:""));
		TabSuggestElt.push(Elt);
		if ( typeof className != "undefined" )
			Elt.setAttribute("synsuggest", className);
	}
	else
		GestionDom.debug("AddInput Error : No element given");
}

function setChargementImmediat(Val) {
	TabSuggestLancement["immediat"] = Val;
}

function setChargementSurDelai(Val) {
	TabSuggestLancement["delai"] = Val;
}

function setChargementSurFocus(Val) {
	TabSuggestLancement["surfocus"] = Val;
}

function setChargementSurTouche(Val) {
	TabSuggestLancement["surtouche"] = Val;
}

function Start() {
	GestionDom.DomReadySuggests(__Start, "__start");
}





// Variables globales diverses
RessourcesPath = document.location.protocol;
RessourcesPath += "//www.synomia-autocompletion.com/";

collection = new Array;
SynSuggestsParams = new Array;
var Main = null;
TabSuggestElt = new Array;
var TabSuggestLancement = new Array;
TabSuggestLancement["immediat"] = false;
TabSuggestLancement["delai"] = 0;
TabSuggestLancement["surfocus"] = false;
TabSuggestLancement["surtouche"] = false;






// Fonctions chargement

function SynInitFctSuggest() {
	debug_suggest("SynInitFctSuggest - Ajout de synTxtInput par defaut");
	var Elt = document.getElementById("synTxtInput");
	if ( Elt )
		AddInput(Elt, "SynSuggestDefault");	
};

function __Start() {
	debug_suggest("__Start - Nombre de champ a gerer : "+TabSuggestElt.length);
	for (j=0; j< TabSuggestElt.length; j++) {
		Elt = TabSuggestElt[j];
		if ( Elt ) {
			var Espace = "";
			if ( Elt.className != "" ) Espace = " "; 
			Elt.className += Espace + "SynSuggest";
			Elt.setAttribute("autocomplete","OFF");
		}
	}
	
	if ( TabSuggestLancement["immediat"] ) chargement_immediat();
	if ( TabSuggestLancement["surfocus"] ) chargement_onfocus();
	if ( TabSuggestLancement["surtouche"] ) chargement_onkeypress();
	if ( parseInt(TabSuggestLancement["delai"]) > 0 ) chargement_delai(parseInt(TabSuggestLancement["delai"]));
}

function debug_suggest(Val, type) {
	if ( typeof type == "undefined" ) type=1;
	if ( typeof DebugSug == "undefined" ) { var Ph = window.location.search.substring(1); var nb = Ph.indexOf("DebugSug="); DebugSug=(nb>=0)?Ph.substring(nb+9, nb+10):0; }
	if ( DebugSug && type>=DebugSug ) {
		if ( window.console ) console.log(Val);
		//else alert(Val);
	}
};

debug_suggest("librairie en cours de chargement");
var Cpt_Chargement = 0;
var ChargementTimer = null;
var Script_Data = false;
var Script_Lib = false;
var Script_CSS = false;
var Init_Fields = false;

function chargement(comm) {
	Ph = "Lancement ( "+comm+" )";
	GestionDom.debug(comm);	
	if ( ChargementTimer == null ) {
		ChargementTimer = chargement_engine();
	};
};

function chargement_engine() {
	if ( ChargementTimer != null ) { clearTimeout(ChargementTimer); ChargementTimer = null; };
	Cpt_Chargement++;
	Ph = "Mode auto => Essai "+Cpt_Chargement;
	debug_suggest(Ph);
		
	var ChargementNecessaire = ! ( Script_Data && Script_Lib && Script_CSS );

	if ( ChargementNecessaire && Cpt_Chargement <= 3) {
	
		debug_suggest("Necessite encore des ressources");
		// Rien pour le moment
		var Head = document.getElementsByTagName("head")[0];
		var Elt;
		var supp = "";
		var tmp = querySt("infos");
		if ( tmp ) {
			tmp2 = tmp.split(",");
			for(i=0; i<tmp2.length;i++) supp+="&"+tmp2[i]+"="+querySt(tmp2[i]);
		}
		//console.log("supp : "+supp);
		if ( ! Script_Data ) {
			// on charge les donnees
			Elt = document.createElement("script");
			Elt.type = "text/javascript";
			var src = RessourcesPath+"suggest_data.js.php?mid=fc982d5c25ff37b9768d8057fee2c5b9";
			var collec = getSynCollection();
			if ( collec >= 0 ) src += "&collection="+collec;
			src += supp;
			Elt.src = src;
			Head.appendChild(Elt);
		}
		
		if ( ! Script_CSS  && Cpt_Chargement <= 1 ) {
			// on charge les styles
			Elt = document.createElement("link");
			Elt.type = "text/css";
			Elt.rel="stylesheet";
			Elt.href = RessourcesPath+"suggest.css.php?mid=fc982d5c25ff37b9768d8057fee2c5b9"+supp;
			Head.appendChild(Elt);
			Script_CSS = true;
		}
		
		
		if ( ! Script_Lib  && Cpt_Chargement <= 1 ) {
			// on charge la librairie suggest
			Elt = document.createElement("script");
			Elt.type = "text/javascript";
			Elt.src = RessourcesPath+"suggest_lib.js";
			Head.appendChild(Elt);
		}
		
		
		if ( ChargementTimer == null ) ChargementTimer = setTimeout("chargement_engine()", 1000);
	}
	else {
		if ( ! ChargementNecessaire ) {
			debug_suggest("Toutes les ressources sont presentes");
			

			if ( window.LaunchSuggest && !window.AlreadyLaunched ) {
				debug_suggest("LaunchSuggest : "+window.LaunchSuggest);
				var sugg = window.LaunchSuggest;
				window.LaunchSuggest = false;
				window.AlreadyLaunched = true;
				processSmartInput(sugg);
			}
		}
		else {
			if ( ChargementTimer == null ) ChargementTimer = setTimeout("chargement_engine()", 1000);
		}
	}
}


function chargement_immediat() {
	chargement("Chargement immediat");
};


function chargement_onfocus() {
	var inp;
	for (let i=0; i < TabSuggestElt.length; i++ ) {
		inp = TabSuggestElt[i];
		if (inp.addEventListener) {
			inp.addEventListener("focus", function() { window.LaunchSuggest = this; chargement("Chargement sur focus"); }, false);
		} else {
			if (inp.attachEvent) {
				inp.attachEvent("onfocus", function() { window.LaunchSuggest = event.srcElement; chargement("Chargement sur focus"); });
			} else {
				if ( inp.onfocus && typeof inp.onfocus_tmp != 'function' ) eval("inp.onfocus_tmp = "+inp.onfocus.toString());
				inp.onfocus = function() {
					if ( typeof this.onfocus_tmp == 'function' )
						this.onfocus_tmp();
					window.LaunchSuggest = this;
					chargement("Chargement sur onfocus");
					this.onfocus = this.onfocus_tmp;
				};
			}
		}
	}
};

var synTimer = null;
function chargement_delai(Val) {
	if ( Val == undefined ) Val = 5000;
	synTimer = setTimeout("chargement('Chargement sur delai')", Val);
};

function chargement_onkeypress() {
	var inp;
	for ( i=0; i < TabSuggestElt.length; i++ ) {
		inp = TabSuggestElt[i];
		if ( inp ) {
			if (inp.addEventListener) {
				inp.addEventListener("keydown", function() { window.LaunchSuggest = this; chargement("Chargement sur onkeydown"); }, false);
			} else {
				if (inp.attachEvent) {
					inp.attachEvent("onkeydown", function() {
						window.LaunchSuggest = event.srcElement;
						chargement("Chargement sur onkeydown");
					});
				} else {
					if ( inp.onkeydown && typeof inp.onkeydown_tmp != 'function' ) eval("inp.onkeydown_tmp = "+inp.onkeydown.toString());
					inp.onkeydown = function() {
						if ( typeof this.onkeydown_tmp == 'function' )
							this.onkeydown_tmp();
						window.LaunchSuggest = this;
						chargement("Chargement sur onkeydown");
					};
					inp.onkeydown = function() { chargement("Chargement sur onkeydown"); };
				}
			}
		}
	}
	
};

function querySt(ji) {
hu = window.location.search.substring(1);
gy = hu.split("&");
for (i=0;i<gy.length;i++) {
ft = gy[i].split("=");
if (ft[0] == ji) {
return ft[1];
}
}
}

function getSynCollection() {
	var collec = 0;
	
	// on regarde dans la combo, puis dans l'url
	var synSelect = document.getElementById("synCollectionSelect");
	if (synSelect) collec = synSelect.options[synSelect.selectedIndex].value;

	if ( collec <= 0 ) {
		collec = querySt("collection");
	}
	if ( typeof collec == "undefined" ) collec = 0;
	//console.log("collection detectee : "+collec); 
	return collec;
}


function DomReadySuggests(fn, name)
{
	if ( typeof name == "undefined" ) name = fn.name;
	this.debug("DomReadySuggests - Chargement ASAP : "+name);
	this.TabFnDomReady.push(fn);
	if ( this.isReady ) {
		this.debug("DomReadySuggests - DOM prete, on lance le gestionnaire");
		if ( ! this.ManagerInProgress ) this.__DomReadySuggests();
	}
	else {
		if ( this.ManagerCreated ) {
			this.debug("DomReadySuggests - Gestionnaire deja cree, aucune action requise");
		}
		else {
			this.debug("DomReadySuggests - DOM pas prete, on cree l'event qui appelera le gestionnaire");
			this.DomCreateManager();
		}
	}
}

function DomCreateManager(force) {
	if ( typeof force == "undefined" ) force = false;
	//W3C
	if(document.addEventListener)
	{
		if ( ! this.ManagerCreated ) {
			document.addEventListener("DOMContentLoaded", function() { __DomReadySuggests_Callback(GestionDom, "__DomReadySuggests"); } , false);
			this.debug("DomReadySuggests - addEventListener sur DOMContentLoaded cree");
			this.ManagerCreated = true;
		}
		if ( force ) {
			window.setTimeout(function() { GestionDom.debug("DomReadySuggests - Execution du timer de compatibilite"); __DomReadySuggests_Callback(GestionDom, "__DomReadySuggests"); }, 2000);
			this.debug("DomReadySuggests - timer de compatibilite ajoute");
		}
	}
	//IE
	else
	{
		if ( ! this.ManagerCreated ) {
			fn2 = document.onreadystatechange;
			if ( typeof fn2 == 'function' ) { this.TabFnDomReady.unshift(fn2); this.debug("DomReadySuggests - onreadystatechange existe, on s'ajoute au gestionnaire existant"); }
			document.onreadystatechange = function() { __DomReadySuggests_Callback(GestionDom, "readyStateSuggests"); };
			this.debug("DomReadySuggests - onreadystatechange cree");
			this.ManagerCreated = true;
		}
		if ( force ) {
			window.setTimeout(function() { GestionDom.debug("DomReadySuggests - Execution du timer de compatibilite"); __DomReadySuggests_Callback(GestionDom, "readyStateSuggests"); }, 2000);
			this.debug("DomReadySuggests - timer de compatibilite ajoute");
		}
	}
}

//IE execute function
function readyStateSuggests()
{
	//dom is ready for interaction
	this.debug("readyStateSuggests - on teste l'etat d'intereactivite de la page", 2);
	if(
		document.readyState == "complete"
		||
		document.readyState == "interactive"
	)
	{
		this.debug("readyStateSuggests - page interactive, on regarde si la page est manipulable");
		if ( typeof document.getElementsByTagName('body')[0] != "undefined" ) {
			this.debug("readyStateSuggests - body accessible, on lance le gestionnaire");
			this.__DomReadySuggests();
		}
		else {
			this.debug("readyStateSuggests - body non accessible, on attends encore");
			window.setTimeout(function() { __DomReadySuggests_Callback(GestionDom, "readyStateSuggests"); }, 1000);
		}
	}
	else {
		this.debug("readyStateSuggests - page non interactive");
	}
}

function __DomReadySuggests() {
	this.debug("__DomReadySuggests - gestionnaire en cours", 2);
	this.debug("Il y a encore "+this.TabFnDomReady.length+" fonctions a traiter");
	if(!this.isReady) { this.isReady = true; }
	this.ManagerInProgress = true;
	for(i=0; i<this.TabFnDomReady.length; i++) {
		if ( this.TabFnDomReady[i] ) {
			this.debug("execution de la fonction "+(i+1)+" ("+this.TabFnDomReady[i].name+")");
			fn = this.TabFnDomReady[i];
			this.TabFnDomReady[i] = null;
			fn();
		}
	}
	this.ManagerInProgress = false;
	this.TabFnDomReady = new Array;
	this.debug("__DomReadySuggests - Fin du gestionnaire");
}

function __DomReadySuggests_Callback(Classe, fn) {
	Classe[fn]();
}

if ( !window.GestionDom || typeof GestionDom != 'object' ) {
 
GestionDom = {};
// Fonctions interactions avec le browser
GestionDom.TabFnDomReady = new Array;
GestionDom.isReady = false;
GestionDom.forceOnTimer = false;
GestionDom.ManagerCreated = false;
GestionDom.ManagerInProgress = false;
GestionDom.DomReadySuggests = DomReadySuggests;
GestionDom.readyStateSuggests = readyStateSuggests; 
GestionDom.__DomReadySuggests = __DomReadySuggests;
GestionDom.DomCreateManager = DomCreateManager;
GestionDom.debug = function(Val, type) {
	debug_suggest(Val, type);
};


/*
if (    typeof document.getElementsByTagName != 'undefined'
	&& typeof document.getElementById != 'undefined' 
	&& ( document.getElementsByTagName('body')[0] != null
		|| document.body != null ) ) {
	GestionDom.isReady = false;
	//GestionDom.isReady = true;
	
}
*/

}

GestionDom.DomReadySuggests(SynInitFctSuggest, "SynInitFctSuggest");

SynSuggest = new SynSuggests();
}
if ( loadACNow ) { GestionDom.DomReadySuggests( function() {
// exemple qui prend tous les input dont le name vaut "q" ou "mot"
// les associe pour l'utilisation des Suggest, et leur retire le focus 
var Elt=document.getElementsByTagName("input");
for (let j=0; j< Elt.length; j++) {
	if ( Elt[j].name == "q" || Elt[j].name == "mot" ) {
		SynSuggest.AddInput(Elt[j]);
		Elt[j].blur();
	}
}
SynSuggest.setChargementSurFocus(true);
SynSuggest.Start();
}, "params" ); }
debug_suggest("librairie chargee");