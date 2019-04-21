let splitByRow = (~items, ~maxRowItems) => {
  let appendNewRow = (list, item) => {
    [[item], ...list];
  };

  let appendNewItemToRow = (list, item, row) => {
    let row = [item, ...row];
    let list = List.tl(list);
    [row, ...list];
  };

  let foldFn = (acc, item) => {
    let row = List.hd(acc);

    if (!(List.length(row) === maxRowItems)) {
      appendNewItemToRow(acc, item, row);
    } else {
      appendNewRow(acc, item);
    };
  };

  List.fold_left(foldFn, [[]], items);
};