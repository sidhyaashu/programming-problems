// In JavaScript, there isn't native support for abstract classes like in other languages such as Java or Python. However, you can achieve similar behavior using conventions and patterns. One common approach is to create a constructor function that throws an error if it's directly instantiated, and then have subclasses inherit from it. Here's an example:

// Define an abstract class
class AbstractClass {
    constructor() {
        if (new.target === AbstractClass) {
            throw new Error("Cannot instantiate abstract class");
        }
    }
    // Define a method in the abstract class
    abstractMethod() {
        throw new Error("Abstract method must be overridden");
    }
}

// Subclass extending the abstract class
class ConcreteClass extends AbstractClass{
    constructor() {
        super(); // Call the parent constructor
    }
    // Implement abstract method in the subclass
    abstractMethod() {
        console.log("Implemented abstract method");
    }
}
// Inherit from the abstract class
// ConcreteClass.prototype = Object.create(AbstractClass.prototype);
;
// Example usage
// Attempting to instantiate AbstractClass will throw an error
// var obj = new AbstractClass(); // Throws an error
// Instantiate ConcreteClass
var obj2 = new ConcreteClass();
obj2.abstractMethod(); // Outputs: Implemented abstract method