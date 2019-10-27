<h1 align="center">Calculating digits of PI in C</h1>

<div align="center">

<p align="center">
    <img src="https://i.imgur.com/x0rhLQ9.jpg" width="300"/>
</p>

programm that calculates digits of PI using the [mpfr library](https://www.mpfr.org/). The calculation uses the [Machin-like Formula](https://en.wikipedia.org/wiki/Machin-like_formula) from Hwang Chien-Lih to approximate PI/4.
</div>


## Usage

compiles the code using no optimization, O3 or Ofast. Set Precision field and run code.

```bash
make calculatePi
make calculatePiO3
make calculatePiFaster
```

compares 2 files, used for testing correctness
```bash
make compare

./compare file1.txt file2.txt
```


