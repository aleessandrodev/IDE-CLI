<div align="center">

# INIDE

[![Language](https://img.shields.io/badge/language-C%2B%2B-00599C?logo=c%2B%2B&logoColor=white)](#)
[![Version](https://img.shields.io/badge/version-v0.0.6a-blue)](#)
[![Platform](https://img.shields.io/badge/platform-Windows-0078D6?logo=windows&logoColor=white)](#)
[![Status](https://img.shields.io/badge/status-in%20development-orange)](#)
[![License](https://img.shields.io/badge/license-MIT-green)](#)

🇬🇧 English · 🇮🇹 [Italiano](https://github.com/aleessandrodev/INIDE-terminal_based_IDE/blob/v0.0.6a/README.it.md)
</div>
<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/aaf73183-f740-4e63-af15-edbdedd55363" />

---

## 📖 Table of Contents

- [Description](#-description)
- [What's new in v0.0.6a](#-whats-new-in-v006a)
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

**INIDE** is a command-line IDE written in **C++**. It runs entirely in the terminal, has a **VIM**-inspired editor, and lets you write, compile and run code without leaving the program.

> ⚠️ The project is under active development (`v0.0.6a`): some features may change.

---

## ✨ What's new in v0.0.6a

- Fixed a bug where `:r` could not run executable files such as `.exe` or `.py`, etc.
- Added backspace at the start of a line
- Fixed a bug that prevented writing code beyond the number of lines in the terminal

---

## 📑 The three pages

INIDE is organized into three pages:

| Page          | Description                                                                          |
| ------------- | ------------------------------------------------------------------------------------ |
| **Functions** | List and execution of commands (save, compile, create file, etc.)                    |
| **Editor**    | Edit the open file                                                                   |
| **Console**   | Regular console: create folders, navigate, create or delete files with system commands |

---

## ⌨️ Commands

Commands are typed from the **Functions** page.

| Command | Action                                      |
| ------- | ------------------------------------------- |
| `:q`    | Quit the program                            |
| `:s`    | Save the file                               |
| `:b`    | Go back                                     |
| `:c`    | Compile (C++ only)                          |
| `:r`    | Run the file                                |
| `:cr`   | Compile and run (C++ only)                  |
| `:ac`   | Auto compile (C++ only)                     |
| `:acr`  | Auto compile and run (C++ only)             |
| `:sfe`  | Search for a file by extension              |
| `:sfn`  | Search for a file by name                   |
| `:cf`   | Create a file                               |
| `:of`   | Open a file                                 |

> 💡 `:c` and `:cr` only work for **C++**. `:r` works for every language that can be opened with a double click (e.g. `py`, `html`).

---

## 🌐 Supported languages

Extensions recognized by the editor:

| Extension       | Language   |
| --------------- | ---------- |
| `.cpp`          | C++        |
| `.py`           | Python     |
| `.java`         | Java       |
| `.js`           | JavaScript |
| `.html`, `.htm` | HTML       |
| `.css`          | CSS        |
| `.json`         | JSON       |

---

## 🗂️ Project structure

```
INIDE/
├── main.cpp          # Entry point
├── global.h/.cpp     # Global variables and settings
├── codeLine.h/.cpp   # Code line management
├── cursor.h/.cpp     # Cursor management
├── console.h/.cpp    # Terminal input/output
├── read.h/.cpp       # File reading
├── write.h/.cpp      # File writing
├── language.h/.cpp   # Language recognition
├── runner.h/.cpp     # Compilation and execution
├── fileIO.h/.cpp     # File input/output
└── SyntaxHighlighting.h
```

---

## 📋 Requirements

- **Windows**
- **g++ (MinGW)** to compile the sources
- To use `:c` / `:cr`, a C++ compiler reachable from the terminal is required

---

## 🚀 Build

```
git clone https://github.com/aleessandrodev/INIDE.git
cd INIDE
g++ *.cpp -o INIDE.exe
```

---

## 🛣️ Roadmap

- [x] VIM-inspired editor
- [x] Compile and run from the editor
- [x] Built-in console
- [ ] Syntax highlighting
- [ ] Undo / Redo
- [ ] Copy / Paste
- [ ] Multiple cursors
- [ ] Linux and macOS support

---

## 🤝 Contributing

1. **Fork** the project
2. Create a branch (`git checkout -b feature/feature-name`)
3. Commit your changes (`git commit -m "Add feature-name"`)
4. Push to the branch (`git push origin feature/feature-name`)
5. Open a **Pull Request**

For bugs or suggestions, open an [issue](https://github.com/aleessandrodev/INIDE/issues).

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
