<div align="center">

# 🖥️ INIDE

**Un editor di codice e IDE da terminale, ispirato a VIM, per Windows.**

![Language](https://img.shields.io/badge/language-C%2B%2B-00599C?logo=c%2B%2B&logoColor=white)
![Version](https://img.shields.io/badge/version-v0.0.5a-blue)
![Platform](https://img.shields.io/badge/platform-Windows-0078D6?logo=windows&logoColor=white)
![Status](https://img.shields.io/badge/status-in%20sviluppo-orange)
![License](https://img.shields.io/badge/license-MIT-green)

🇬🇧 [English](README.md) · 🇮🇹 Italiano

</div>

---

## 📖 Indice

- [Descrizione](#-descrizione)
- [Correzioni](#-correzioni-nella-v0004b)
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

**INIDE** è un IDE a riga di comando scritto in **C++**. Funziona interamente nel terminale, ha un editor ispirato a **VIM** e permette di scrivere, compilare ed eseguire codice senza uscire dal programma.

> ⚠️ Il progetto è in sviluppo attivo (`v0.0.5a`): alcune funzionalità possono cambiare.

---

## ✨ Cosa c'è di nuovo nella v0.0.5a

  - Aggiunta sottolineatura della sintassi usando [SyntaxHighlighting-Cplusplus-Library](https://github.com/aleessandrodev/SyntaxHighlighting-Cplusplus-Library)
  - Migliorato il sistema per andare a capo in IDE: premendo `ENTER` nel mezzo di una linea di codice ora si dividerà in due linee.

---

## 📑 Le tre pagine

INIDE è organizzato in tre pagine:

| Pagina | Descrizione |
| ------ | ----------- |
| **Funzioni** | Elenco ed esecuzione dei comandi (salvataggio, compilazione, creazione file, ecc.) |
| **Editor** | Modifica del file aperto |
| **Console** | Console normale: crea cartelle, spostati, crea o elimina file con i comandi di sistema |


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
| `:sfe` | Cerca un file dall'estensione **(nuovo)** |
| `:sfn` | Cerca un file dal nome **(nuovo)** |
| `:cf`  | Crea un file |
| `:of`  | Apri un file |


> 💡 `:c` e `:cr` funzionano solo per **C++**. `:r` funziona per tutti i linguaggi che si possono aprire con un doppio click (es. `py`, `html`).

---

## 🌐 Linguaggi supportati

Estensioni riconosciute dall'editor:

| Estensione | Linguaggio |
| ---------- | ---------- |
| `.cpp`          | C++ |
| `.py`           | Python |
| `.java`         | Java |
| `.js`           | JavaScript |
| `.html`, `.htm` | HTML |
| `.css`          | CSS |
| `.json`         | JSON |

---

## 🗂️ Struttura del progetto

```
INIDE/
├── main.cpp          # Punto di ingresso
├── global.h/.cpp     # Variabili e impostazioni globali
├── codeLine.h/.cpp   # Gestione delle righe di codice
├── cursor.h/.cpp     # Gestione del cursore
├── console.h/.cpp    # Input/output su terminale
├── read.h/.cpp       # Lettura dei file
├── write.h/.cpp      # Scrittura dei file
├── language.h/.cpp   # Riconoscimento dei linguaggi
├── runner.h/.cpp     # Compilazione ed esecuzione
├── fileIO.h/.cpp     # Input/Output dei file (funzione di salvataggio)
└── SyntaxHighlighting.h
```

---

## 📋 Requisiti

- **Windows**
- **g++ (MinGW)** per compilare i sorgenti
- Per usare `:c` / `:cr` serve un compilatore C++ raggiungibile dal terminale

---

## 🚀 Build

```bash
git clone https://github.com/aleessandrodev/INIDE.git
cd INIDE
g++ *.cpp -o INIDE.exe
```


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

Per bug o suggerimenti apri una [issue](https://github.com/aleessandrodev/INIDE/issues).

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
