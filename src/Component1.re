module Styles = {
  open Css;

  let container =
    style([height(vh(100.)), display(flexBox), background(hex("fff"))]);
};

let renderItems = width => {
  let items = [
    <GridItem width key="1" />,
    <GridItem width key="2" />,
    <GridItem width key="3" />,
    <GridItem width key="4" />,
    <GridItem width key="5" />,
  ];

  let rows = GridTasks.splitByRow(~items, ~maxRowItems=3);
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
let make = () =>
  <div className=Styles.container>
    <Grid itemWidth=200 render=renderItems />
  </div>;