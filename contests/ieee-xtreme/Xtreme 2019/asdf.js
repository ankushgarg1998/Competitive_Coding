function main() {
    // write your code here.
    // call functions `nextString`, `nextFloat` and `nextInt` 
    // to read the next token of input (ignoring whitespace)
    // Alternatively, you can create your own input parser functions
    // use console.log() to write to stdout

    var i = nextInt();
    console.log(i);
    var l1 = '', l2 = [];
    var s = nextString();
    while(s !== '{"publisher":') {
        l1 += s;
        s = nextString();
    }
    console.log(l1);
    while(s !== '') {
        var lt = s;
        s = nextString();
        while(s !== '{"publisher":' && s !== '') {
            lt += s;
            s = nextString();
        }
        l2.push(lt);
    }
    console.log(l2);
    
    var obj1 = JSON.parse(l1);
    var obj2 = [];
    l2.forEach((str) => {
        console.log(str);
        obj2.push(JSON.parse(str));
    });
    
    // console.log(obj1);
    console.log(obj2);
    
    
}

// default parsers for JS.
function nextInt() {
    return parseInt(nextString());
}

function nextFloat() {
    return parseFloat(nextString());
}

function nextString() {
    var next_string = "";
    clearWhitespaces();
    while (input_cursor < input_stdin.length && !isWhitespace(input_stdin[input_cursor])) {
        next_string += input_stdin[input_cursor];
        input_cursor += 1;
    }
    return next_string;
}

function nextChar() {
    clearWhitespaces();
    if (input_cursor < input_stdin.length) {
        return input_stdin[input_cursor++];
    } else {
        return '\0';
    }
}

process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_cursor = 0;
process.stdin.on('data', function (data) { input_stdin += data; });
process.stdin.on('end', function () { main(); });

function isWhitespace(character) {
    return ' \t\n\r\v'.indexOf(character) > -1;
}

function clearWhitespaces() {
    while (input_cursor < input_stdin.length && isWhitespace(input_stdin[input_cursor])) {
        // ignore the next whitespace character
        input_cursor += 1;
    }  
}