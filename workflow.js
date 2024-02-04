document.getElementById("sudoku-board").addEventListener("keyup", function(event) {
    if (event.target && event.target.nodeName == "TD") {
      var validNum = /[1-9]/;
      var tdEl = event.target;
      if (tdEl.innerText.length > 0 && validNum.test(tdEl.innerText[0])) {
        tdEl.innerText = tdEl.innerText[0];
      } else {
        tdEl.innerText = "";
      }
    }
  });

  document.getElementById("solve-button").addEventListener("click", function(event) {
    var boardString = boardToString();
    var solution = SudokuSolver.solve(boardString);
    if (solution) {
      stringToBoard(solution);
    } else {
      alert("Invalid board!");
    }
  });

  document.getElementById("clear-button").addEventListener("click", clearBoard);

  function clearBoard() {
    var tds = document.getElementsByTagName("td");
    for (var i = 0; i < tds.length; i++) {
      tds[i].innerText = "";
    }
  }

  function boardToString() {
    var string = "";
    var validNum = /[1-9]/;
    var tds = document.getElementsByTagName("td");
    for (var i = 0; i < tds.length; i++) {
      if (validNum.test(tds[i].innerText[0])) {
        string += tds[i].innerText;
      } else {
        string += "-";
      }
    }
    return string;
  }

  function stringToBoard(string) {
    var currentCell;
    var validNum = /[1-9]/;
    var cells = string.split("");
    var tds = document.getElementsByTagName("td");
    for (var i = 0; i < tds.length; i++) {
      currentCell = cells.shift();
      if (validNum.test(currentCell)) {
        tds[i].innerText = currentCell;
      }
    }
  }