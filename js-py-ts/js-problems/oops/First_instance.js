const { Animal } = require("./First_class");

const first_animal = new Animal("Sidhya", 45);

console.log(first_animal);
console.log(first_animal.getInfo());

const second_animal = new Animal("Subho", 23);

console.log(second_animal);
console.log(second_animal.getInfo());

const third_animal = new Animal("Tanmay", 24);

console.log(third_animal);
console.log(third_animal.getInfo());