module Styles = {
  open Css;

  let container =
    style([height(vh(100.)), display(flexBox), background(hex("fff"))]);
};

let maxRowItems = 3;

let renderItems = width => {
  let items = [
    <GridItem width key="1" />,
    <GridItem width key="2" />,
    <GridItem width key="3" />,
    <GridItem width key="4" />,
    <GridItem width key="5" />,
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

  <div className=Styles.container>
    <Grid itemWidth={vw / maxRowItems} render=renderItems />
  </div>;
};