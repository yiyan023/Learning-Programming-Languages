/**
 * @return {Function}
 */
var createHelloWorld = function() {
    return () => "Hello World"; 
    /* You put the parameters inside () 
       Empty () indicates any parameter will return "Hello World" */
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */