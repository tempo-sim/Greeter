# Greeter
Greeter is a simple example plugin demonstrating the use of TempoScripting to add and implement RPCs.

Your project must already be using [Tempo](https://github.com/tempo-sim/Tempo). Specifically
- Tempo in the Plugins directory
- *.Target.cs files set up to use the Tempo build Toolchains (see [here](https://github.com/tempo-sim/Tempo/tree/tempo-readme#project-changes))

Once you build your project with Tempo and the Greeter plugin, you can:

1. With your Tempo project open in Unreal Editor, from the root of your project, activate the Tempo virtual environment (`source ./TempoEnv/bin/activate` on Linux & Mac, or `source ./TempoEnv/Scripts/activate` on Windows)
2. From the Greeter Plugin's C++ classes, add a `GreeterActor` to the world and hit Play
3. Start the Python interpreter (`python` on Linux & Mac, or `winpty python` on Windows)
4. Test out the auto-generated Greeter API:
```
import tempo.greeter as tg
tg.greet("Hello from client!")
```
The server should respond `"Hello from server!"` and draw a green sphere at the location of the `GreeterActor` in the world.

That's it! See if you can change the server's response or the color of the sphere.

Then, use the Greeter example as a guide to implement your own RPCs!
