const { Dog } = require("./Inheritance.js")
const { Cat } = require("./Encapsulation.js")

const dog1 = new Dog("Sidhay",23,"zebra")
const cat1 = new Cat("Sidhay",23,"5kg")

//inheritence
// console.log(dog1)
// console.log(dog1.bark())
// console.log(dog1.showInfo())

//encapsulation
console.log(cat1)
console.log(cat1.age)
console.log(cat1.name)
// console.log(cat1.weight) // cant get property bcz it's private
console.log(cat1.getWeight())
cat1.setWeight("20kg")
console.log(cat1.getWeight())