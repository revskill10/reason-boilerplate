let make = (~title, (), content) =>
  {j|
  <!DOCTYPE html>
    <html>
      <head>
        <title>$title</title>
      </head>
      <body>
        <div id="root">$content</div>
        <script src="/assets/js/main.502be691.js"></script>
      </body>
    </html>
|j};

module Helper = {
  let add = [%raw {|
    function(a, b) {
      console.log("hello from raw JavaScript!");
      return a + b
    }
  |}];
}