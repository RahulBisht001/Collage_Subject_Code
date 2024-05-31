const identifyCreditCard = (number) => {
    const numString = number.toString();
    const len = numString.length;

    // for visa
    if ((len == 13 || len == 16) && numString[0] === "4") {
        console.log("This is a Visa Card");
    }
    // for american express
    else if (len == 15 && numString[0] === "3" && (numString[1] === "4" || numString[1] == "7")) {
        console.log("This is a American Express Card");
    } else console.log("This is not a valid card number");
};

const inputCardNumber = document.getElementById("card");
const btn = document.getElementById("btn");

btn.addEventListener("click", () => {
    const cardNum = inputCardNumber.value;
    identifyCreditCard(cardNum);
});
