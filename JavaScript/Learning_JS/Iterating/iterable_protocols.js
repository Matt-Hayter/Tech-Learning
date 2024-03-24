//In 2015, new syntax introduced to introduce iterable features to some data types
//Built in functionality to iterate over these iterables
//Some objects have an iterator, which should implement the iterator protocol: implement .next(), .value and .done
//Can create your own iterator (implementing next, done and value) -> Better to just use the generator method (look up)

const str = "Matthew" 

for(const char of str) {
    console.log(char)
}

const arr = ["M", "A", "T", "T"]

for(const element of arr) {
    console.log(element)
}