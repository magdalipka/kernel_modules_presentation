const { open } = require("fs").promises;

const path = "/dev/messenger_server";
const textLength = 9;

async function writer() {
  if (process.argv.length < 3) {
    throw new Error("Wrong number of arguments! :( node writer.js <Text>");
  }
  const text = new Buffer.from(process.argv[2]);
  const fileDescriptor = await open(path, "w");
  await fileDescriptor.write(text, 0, text.length, null);
}

writer();
