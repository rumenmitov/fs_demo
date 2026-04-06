package .ru.dz.demo;

import .phantom.os;
import .internal.io.tty;
import .internal.long;
import .internal.double;
import .internal.float;
import .internal.string;
import .internal.wasm;


class fs_demo {
    void run(var console : .internal.io.tty)
    {
      var wamr 	: .internal.wasm;
      var args 	: .internal.string[];
      var result: .internal.object;

      wamr = new .internal.wasm();
      args = new .internal.string[]();

      console.putws("fs_demo: ");

      wamr.loadModule(getBinary());
      result = wamr.wasiInvokeStart(args);

      console.putws(result.toString());
      console.putws("\n");
    }

    .internal.string getBinary()
    {
      return import "src/fs_demo/assets/fs_demo.wasm";
    }
};
