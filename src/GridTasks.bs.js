// Generated by BUCKLESCRIPT VERSION 5.0.2, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var $$Array = require("bs-platform/lib/js/array.js");

function splitByRow(items, maxRowItems) {
  var foldFn = function (acc, item) {
    var row = List.hd(acc);
    if (List.length(row) !== maxRowItems) {
      var list = acc;
      var item$1 = item;
      var row$1 = row;
      var row$2 = /* :: */[
        item$1,
        row$1
      ];
      var list$1 = List.tl(list);
      return /* :: */[
              row$2,
              list$1
            ];
    } else {
      var list$2 = acc;
      var item$2 = item;
      return /* :: */[
              /* :: */[
                item$2,
                /* [] */0
              ],
              list$2
            ];
    }
  };
  var l = List.fold_left(foldFn, /* :: */[
        /* [] */0,
        /* [] */0
      ], items);
  return $$Array.of_list(List.map($$Array.of_list, l));
}

exports.splitByRow = splitByRow;
/* No side effect */
