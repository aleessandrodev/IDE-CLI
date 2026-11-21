<div align="center">

# 🖥️ IDE-CLI

**Un editor di codice e IDE da terminale, ispirato a VIM, per Windows.**

![Language](https://img.shields.io/badge/language-C%2B%2B-00599C?logo=c%2B%2B&logoColor=white)
![Version](https://img.shields.io/badge/version-v0.0.4a-blue)
![Platform](https://img.shields.io/badge/platform-Windows-0078D6?logo=windows&logoColor=white)
![Status](https://img.shields.io/badge/status-in%20sviluppo-orange)
![License](https://img.shields.io/badge/license-MIT-green)

🇬🇧 [English](README.md) · 🇮🇹 Italiano

</div>

---

## 📖 Indice

- [Descrizione](#-descrizione)
- [Funzionalità](#-funzionalità)
- [Le tre pagine](#-le-tre-pagine)
- [Comandi](#-comandi)
- [Linguaggi supportati](#-linguaggi-supportati)
- [Struttura del progetto](#-struttura-del-progetto)
- [Requisiti](#-requisiti)
- [Build](#-build)
- [Roadmap](#-roadmap)
- [Contribuire](#-contribuire)
- [Licenza](#-licenza)
- [Autore](#-autore)

---

## 📝 Descrizione

**IDE-CLI** è un IDE a riga di comando scritto in **C++**. Funziona interamente nel terminale, ha un editor ispirato a **VIM** e permette di scrivere, compilare ed eseguire codice senza uscire dal programma.

> ⚠️ Il progetto è in sviluppo attivo (`v0.0.4a`): alcune funzionalità possono cambiare.

---

## ✨ Funzionalità

- ✏️ Editor di testo nel terminale, ispirato a VIM
- ⚙️ **Compilazione** di file C++ direttamente dall'editor (manuale o automatica)
- ▶️ **Esecuzione** di file in vari linguaggi (py, html, ecc.)
- 🖨️ **Console integrata**: una console vera, con `mkdir`, `cd`, `del`, ecc.
- 📂 Creazione, ricerca e apertura di file dall'IDE
- 🌐 Riconoscimento di più linguaggi in base all'estensione

---

## 📑 Le tre pagine

IDE-CLI è organizzato in tre pagine:

| Pagina | Descrizione |
| ------ | ----------- |
| **Funzioni** | Elenco ed esecuzione dei comandi (salvataggio, compilazione, creazione file, ecc.) |
| **Editor** | Modifica del file aperto |
| **Console** | Console normale: crea cartelle, spostati, crea o elimina file con i comandi di sistema |

<!-- TODO: descrivi come si passa da una pagina all'altra (tasti o comandi) -->

---

## ⌨️ Comandi

I comandi si digitano dalla pagina **Funzioni**.

| Comando | Azione |
| ------- | ------ |
| `:q`   | Esci dal programma |
| `:s`   | Salva il file |
| `:b`   | Torna indietro |
| `:c`   | Compila (solo C++) |
| `:r`   | Esegui il file |
| `:cr`  | Compila ed esegui (solo C++) |
| `:ac`  | Compilazione automatica (solo C++) |
| `:acr` | Compilazione automatica ed esecuzione (solo C++) |
| `:sf`  | Cerca un file |
| `:cf`  | Crea un file |
| `:of`  | Apri un file |

<!-- TODO: spiega in una riga cosa significa "automatica" per :ac e :acr -->

> 💡 `:c` e `:cr` funzionano solo per **C++**. `:r` funziona per tutti i linguaggi che si possono aprire con un doppio click (es. `py`, `html`).

---

## 🌐 Linguaggi supportati

Estensioni riconosciute dall'editor:

| Estensione | Linguaggio |
| ---------- | ---------- |
| `.cpp`         | C++ |
| `.py`          | Python |
| `.java`        | Java |
| `.js`          | JavaScript |
| `.html`, `.htm`| HTML |
| `.css`         | CSS |
| `.json`        | JSON |

---

## 🗂️ Struttura del progetto

```
IDE-CLI/
├── main.cpp          # Punto di ingresso
├── global.h/.cpp     # Variabili e impostazioni globali
├── codeLine.h/.cpp   # Gestione delle righe di codice
├── cursor.h/.cpp     # Gestione del cursore
├── console.h/.cpp    # Input/output su terminale
├── read.h/.cpp       # Lettura dei file
├── write.h/.cpp      # Scrittura dei file
├── language.h/.cpp   # Riconoscimento dei linguaggi
└── compiler.h/.cpp   # Compilazione ed esecuzione
```

---

## 📋 Requisiti

- **Windows**
- **g++ (MinGW)** per compilare i sorgenti
- Per usare `:c` / `:cr` serve un compilatore C++ raggiungibile dal terminale

---

## 🚀 Build

```bash
git clone https://github.com/aleessandrodev/IDE-CLI.git
cd IDE-CLI
g++ *.cpp -o ide-cli.exe
```

<!-- TODO: se serve uno standard specifico, aggiungi -std=c++17 (o quello corretto) -->


---

## 🛣️ Roadmap

- [x] Editor ispirato a VIM
- [x] Compilazione ed esecuzione da editor
- [x] Console integrata
- [ ] Syntax highlighting
- [ ] Undo / Redo
- [ ] Supporto Linux e macOS

---

## 🤝 Contribuire

1. Fai un **fork** del progetto
2. Crea un branch (`git checkout -b feature/nome-feature`)
3. Fai commit (`git commit -m "Aggiunge nome-feature"`)
4. Fai push (`git push origin feature/nome-feature`)
5. Apri una **Pull Request**

Per bug o suggerimenti apri una [issue](https://github.com/aleessandrodev/IDE-CLI/issues).

---

## 📄 Licenza

Distribuito sotto licenza **MIT**. Vedi il file `LICENSE`.

---

## 👤 Autore

**Alessandro** — [@aleessandrodev](https://github.com/aleessandrodev)

---

<div align="center">

Se il progetto ti piace, lascia una ⭐

</div>
