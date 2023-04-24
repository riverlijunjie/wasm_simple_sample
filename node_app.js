const createModule = require('./build/wasm_test.js.js');

createModule().then(function(Module) {
  console.log('WASM module was initialized');
});
