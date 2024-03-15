// ================================USES OF PROTOTYPE=======================================
// Constructor Functions: When you create custom objects using constructor functions, you can add methods and properties to all instances of that object using the prototype property. For example:

function Person(name,age){
    this.name = name;
    this.age = age
}

Person.prototype.greet = function(){
    return `Hello my name is ${this.name} and age is ${this.age}`
}

// let person = new Person("Sidhya", 20)
// console.log(person.greet())


function Animal(name){
    this.name = name
}

function Dog(name,breed){
    Animal.call(this,name);
    this.breed = breed
}
Dog.prototype.constructor = Dog

Dog.prototype.bark = function(){
    return`Bhaow Bhaow`
}

let dog = new Dog("Shiba","zebra")
console.log(dog.bark())
console.log(dog.sayMyName())

