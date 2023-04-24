const path = require('path');
const httpServer = require('http-server');

const root = path.join(__dirname, '.');
const port = process.env['PORT'] || 8081;
const host = '127.0.0.1';

const server = httpServer.createServer({
  root,
  robots: true,
  headers: {
    'Access-Control-Allow-Origin': '*',
    'Access-Control-Allow-Credentials': 'true',
    'Cross-Origin-Opener-Policy': 'same-origin',
    'Cross-Origin-Embedder-Policy': 'require-corp',
  },
  cors: true,
  corsHeaders: 'X-Test',
  ext: true,
  brotli: true,
  gzip: true
});

server.listen(port, host, () => {
  console.log(`= Server is running on 'http://${host}:${port}'`);
});
