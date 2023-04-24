# install node
```sh
# https://volta.sh/
# install Volta
curl https://get.volta.sh | bash

# install Node
volta install node

# start using Node
node
```

# install emscripten
```
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
git pull
./emsdk install latest
./emsdk activate latest
source ./emsdk_env.sh
```


# build
```sh
mkdir build
cd build
cmake ..
make
# or build in docker: 
# - docker run -it --rm -v $(pwd):/project emscripten/emsdk
# - emcmake cmake ..
# - emmake make
npm i
```

# run nodejs
`npm run nodejs`
    
# run nodejs
- `npm run browser`
- open [http://127.0.0.1:8081](http://127.0.0.1:8081) and open browser console
