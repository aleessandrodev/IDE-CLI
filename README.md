<div align="center">

# 🖥️ INIDE

**A VIM-inspired code editor and IDE that lives entirely in your terminal. Windows only.**

![Language](https://img.shields.io/badge/language-C%2B%2B-00599C?logo=c%2B%2B&logoColor=white)
![Version](https://img.shields.io/badge/version-v0.0.4a-blue)
![Platform](https://img.shields.io/badge/platform-Windows-0078D6?logo=windows&logoColor=white)
![Status](https://img.shields.io/badge/status-in%20development-orange)
![License](https://img.shields.io/badge/license-MIT-green)

🇬🇧 English · 🇮🇹 [Italiano](README.it.md)

</div>

---

## 📖 Table of Contents

- [Description](#-description)
- [Features](#-features)
- [The three pages](#-the-three-pages)
- [Commands](#-commands)
- [Supported languages](#-supported-languages)
- [Project structure](#-project-structure)
- [Requirements](#-requirements)
- [Build](#-build)
- [Roadmap](#-roadmap)
- [Contributing](#-contributing)
- [License](#-license)
- [Author](#-author)

---

## 📝 Description

**IDE-CLI** is a command-line IDE written in **C++**. It runs entirely in the terminal and has a **VIM**-inspired editor, so you can write, compile and run code without ever leaving the program.

> ⚠️ The project is under active development (`v0.0.4a`): some features may change.

---

## ✨ Features

- ✏️ Terminal text editor inspired by VIM
- ⚙️ **Compile** C++ files straight from the editor (manual or automatic)
- ▶️ **Run** files in several languages (py, html, etc.)
- 🖨️ **Built-in console**: a real console, with `mkdir`, `cd`, `del`, etc.
- 📂 Create, search and open files from within the IDE
- 🌐 Recognizes multiple languages by file extension

---

## 📑 The three pages

IDE-CLI is organized into three pages:

| Page | Description |
| ---- | ----------- |
| **Functions** | Lists and runs commands (save, compile, create file, etc.) |
| **Editor** | Edit the currently open file |
| **Console** | A regular console: create folders, navigate, create or delete files with system commands |

<!-- TODO: explain how to switch between pages (keys or commands) -->

---

## ⌨️ Commands

Commands are typed from the **Functions** page.

| Command | Action |
| ------- | ------ |
| `:q`   | Quit |
| `:s`   | Save the file |
| `:b`   | Go back |
| `:c`   | Compile (C++ only) |
| `:r`   | Run the file |
| `:cr`  | Compile and run (C++ only) |
| `:ac`  | Auto compile (C++ only) |
| `:acr` | Auto compile and run (C++ only) |
| `:sf`  | Search for a file |
| `:cf`  | Create a file |
| `:of`  | Open a file |

<!-- TODO: add one line explaining what "auto" means for :ac and :acr -->

> 💡 `:c` and `:cr` only work for **C++**. `:r` works for every language that can be opened with a double click (e.g. `py`, `html`).

---

## 🌐 Supported languages

File extensions recognized by the editor:

| Extension | Language |
| --------- | -------- |
| `.cpp`          | C++ |
| `.py`           | Python |
| `.java`         | Java |
| `.js`           | JavaScript |
| `.html`, `.htm` | HTML |
| `.css`          | CSS |
| `.json`         | JSON |

---

## 🗂️ Project structure

```
IDE-CLI/
├── main.cpp          # Entry point
├── global.h/.cpp     # Global variables and settings
├── codeLine.h/.cpp   # Code line handling
├── cursor.h/.cpp     # Cursor handling
├── console.h/.cpp    # Terminal input/output
├── read.h/.cpp       # File reading
├── write.h/.cpp      # File writing
├── language.h/.cpp   # Language recognition
└── compiler.h/.cpp   # Compilation and execution
```

---

## 📋 Requirements

- **Windows**
- **g++ (MinGW)** to build the sources
- To use `:c` / `:cr`, a C++ compiler must be reachable from the terminal

---

## 🚀 Build

```bash
git clone https://github.com/aleessandrodev/IDE-CLI.git
cd IDE-CLI
g++ *.cpp -o ide-cli.exe
```

<!-- TODO: if a specific standard is required, add -std=c++17 (or the correct one) -->



---

## 🛣️ Roadmap

- [x] VIM-inspired editor
- [x] Compile and run from the editor
- [x] Built-in console
- [ ] Syntax highlighting
- [ ] Undo / Redo
- [ ] Linux and macOS support

---

## 🤝 Contributing

1. **Fork** the project
2. Create a branch (`git checkout -b feature/feature-name`)
3. Commit your changes (`git commit -m "Add feature-name"`)
4. Push the branch (`git push origin feature/feature-name`)
5. Open a **Pull Request**

For bugs or suggestions, open an [issue](https://github.com/aleessandrodev/IDE-CLI/issues).

---

## 📄 License

Distributed under the **MIT** license. See the `LICENSE` file.

---

## 👤 Author

**Alessandro** — [@aleessandrodev](https://github.com/aleessandrodev)

---

<div align="center">

If you like the project, leave a ⭐

</div>
