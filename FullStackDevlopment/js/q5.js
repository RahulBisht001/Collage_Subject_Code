const counter = document.getElementById("counterBtn");

let count = 0;

const bodyElem = document.getElementsByTagName("body")[0];
const arr = ["red", "green", "blue"];

const change = () => {
    console.log(bodyElem);
    counter.innerText = count;
    count++;
    counter.innerText = `Count is : ${count}`;

    bodyElem.style.backgroundColor = arr[count % 3];
};

const intervalId = setInterval(() => {
    change();
}, 1000);

setTimeout(() => {
    clearInterval(intervalId);
}, 10000);
