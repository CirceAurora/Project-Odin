// I DO NOT OWN THIS FILE!
// CONTENTS FROM: https://forums.bohemia.net/forums/topic/202400-list-of-vehicle-base-classes/?do=findComment&comment=3157231
// ALL RIGHTS RESERVED TO THE POSTER

_hiarachy = [];
_exclude = [];

_classes = ( "isClass _x" configClasses( configFile >> "CfgVehicles" ));
[ "Checking_Classes" ] call BIS_fnc_startLoadingScreen;

{
	_parents = [ _x, true ] call BIS_fnc_returnParents;
	reverse _parents;
	_tree = _hiarachy;

	[ linearConversion[ 0, count _classes, _forEachIndex, 0, 1 ] ] call BIS_fnc_progressLoadingScreen;
	{
		_x params[ "_className" ];
		
		_index = { if ( _x select 0 == _classname )exitWith{ _forEachIndex } }forEach _tree;
		if ( isNil "_index" || _className in _exclude ) exitWith {
			_index = _tree pushBack [ _classname, [] ];
			_tree = _tree select _index select 1;

			{
				_index = _tree pushBack _x;
				_tree = _tree select _index select 1;

			}forEach ( _parents select[ _forEachIndex +1, count _parents ] );
		};
		_tree = _tree select _index select 1;

	}forEach _parents;
}forEach _classes;
[ "Checking_Classes" ] call BIS_fnc_endLoadingScreen;

[ "format_output" ] call BIS_fnc_startLoadingScreen;
_RETURN = [ 13, 10 ];
_TAB = [ 09 ];

_output = "";
_tabIndent = 0;

_fnc_addTabs = {
	params[ "_numTabs" ];
	
	_tabs = "";
	for "_i" from 1 to _numTabs do {
		_tabs = formatText[ "%1%2", _tabs, toString _TAB ];
	};
	
	_tabs
};

_fnc_output = {
	params[ "_array" ];
	
	{
		_x params[ "_class", "_derived" ];
		
		_tabs = [ _tabIndent ] call _fnc_addTabs;
		_output = formatText[ "%1%2%3,%4", _output, _tabs, str _class, toString _RETURN ];
		
		if ( count _derived > 0 ) then {
			_tabIndent = _tabIndent + 1;
			[ _derived ] call _fnc_output;
			_tabIndent = _tabIndent - 1;
		};
	}forEach _array;
};

[ _hiarachy ] call _fnc_output;
[ "format_output" ] call BIS_fnc_endLoadingScreen;

copyToClipboard str _output;
