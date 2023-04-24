const createModule = require('./build/wasm_test.js');

createModule().then(function(Module) {
  console.log('WASM module was initialized');
});
