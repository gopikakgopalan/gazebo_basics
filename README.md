# Build My World: Gazebo Café Simulation

A Gazebo simulation world built for the Udacity Robotics Software Engineer Nanodegree (Project 1, *Build My World*). The world is a small single-floor café with two rover robots, café tables from the Gazebo online library, and a C++ world plugin that prints a welcome message when the world loads.


## Project structure

```
Project1/
├── model/
│   ├── Building/          # Café building (Gazebo Building Editor)
│   │   ├── model.config
│   │   └── model.sdf
│   └── MyRobot/           # Two-wheeled rover (Gazebo Model Editor)
│       ├── model.config
│       └── model.sdf
├── script/
│   └── welcome_message.cpp   # World plugin (C++)
├── world/
│   └── MyCafe.world          # World containing all models
├── CMakeLists.txt            # Builds the plugin
└── README.md
```

## What is in the world

| Item | Source | Notes |
|---|---|---|
| Café building | Building Editor | Single floor, about 10 m × 8 m, with a door in the front wall, a window in the back wall and a 3 m divider wall. Walls are 2.5 m high (editor default) and have colour. |
| MyRobot (×2) | Model Editor | Two instances, `robot_1` and `robot_2`, placed inside the café. |
| Café tables | Gazebo online library | `cafe_table` models placed inside the café. |
| Welcome plugin | `script/welcome_message.cpp` | Prints "Welcome to Gopika's World!" to the terminal. |


## Requirements

- Gazebo (with its development headers, `libgazebo-dev`)
- CMake and a C++ compiler (`build-essential`)
- Internet access on the first launch, so Gazebo can download online-library models if they are not cached

## Build the plugin

From the project root:

```bash
mkdir build
cd build
cmake ../
make
```

This creates `libwelcome_message.so` in the `build` directory.

## Run the world

In the same terminal, set the plugin and model paths, then launch the world. Replace the path with the location of the project on your machine.

```bash
cd ~/Project1/build
export GAZEBO_PLUGIN_PATH=$GAZEBO_PLUGIN_PATH:$(pwd)
export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:$(pwd)/../model
cd ../world
gazebo MyCafe.world
```

The terminal should print:

```
Welcome to Gopika's World!
```

## Troubleshooting

- **`Unable to find uri [model://Building]`**: `GAZEBO_MODEL_PATH` is not set in this terminal, or it does not point to the `model` folder.
- **Plugin not found / no welcome message**: `GAZEBO_PLUGIN_PATH` does not include the `build` folder, or the plugin was not built. Rebuild with `cmake ../ && make`.
- **Café tables missing**: the VM may be offline. Connect to the internet and relaunch so the model can download.
- **Robots stuck in walls or tables**: adjust the pose of each model in the **World** tab and save the world again.

## Editing the models later

- **Robot:** insert `MyRobot` into a world, right-click it and choose **Edit Model**, then save it with the same name and location.
- **Building:** edit `model/Building/model.sdf` in a text editor, or open it with **Edit Model** after inserting it.

## Notes

- The `build/` directory is not part of the submission and is excluded through `.gitignore`.
- The building and robot were created with Gazebo's Building Editor and Model Editor.

## Author

Gopika Korambil Gopalan
