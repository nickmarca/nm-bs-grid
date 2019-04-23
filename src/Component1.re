module Styles = {
  open Css;

  let container =
    style([height(vh(100.)), display(flexBox), background(hex("fff"))]);
};

let renderItems = (maxRowItems, width) => {
  let items = [
    <GridItem width key="1" message="Grid Item 1" />,
    <GridItem width key="2" message="Grid Item 2" />,
    <GridItem width key="3" message="Grid Item 3" />,
    <GridItem width key="4" message="Grid Item 4" />,
    <GridItem width key="5" message="Grid Item 5" />,
  ];

  let rows = GridTasks.splitByRow(~items, ~maxRowItems);
  let rows =
    Array.mapi(
      (i, row) =>
        <GridRow key={string_of_int(i) ++ "_row"}>
          {React.array(row)}
        </GridRow>,
      rows,
    );
  React.array(rows);
};

[@react.component]
let make = () => {
  let vw = Hooks.useVW();

  let lg = Hooks.useMedia("(min-width: 1200px)");
  let md = Hooks.useMedia("(min-width: 992px)");
  let sm = Hooks.useMedia("(min-width: 768px)");

  let maxRowItems =
    switch (lg, md, sm) {
    | (true, _, _) => 4
    | (false, true, _) => 3
    | (false, false, true) => 2
    | _ => 1
    };

  Js.log(maxRowItems);

  <div className=Styles.container>
    <Grid itemWidth={vw / maxRowItems} render={renderItems(maxRowItems)} />
  </div>;
};