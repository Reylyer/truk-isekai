# truk-isekai
2nd generation of gkv-truk-gaming


## Strukrur kode
```
ROOT
├───bin  <-------- hasil compile
├───include   <--- include yang di butuhkan saat compile
│   ├───GL         beberapa cpp yang ada di src dan
│   ├───glm        membutuhkan header akan di taruh disini
│   └───objects <- header world objects, isinya truk givandra, 
│                  vico, dimas, dan david
├───lib  <-------- library yang di butuhkan saat compile(cuman freeglut)
├───obj  <-------- berisi file intermediary object sebelum linking
├───res  <-------- resource folder
│   ├───bmp  <---- bitmap folder
│   └───obj  <---- sekarang tidak terpakai karena mengimport object 
│                  tidak cocok untuk menggunakan glvertex, sangat hurt
│                  performance, hingga tidak playable untuk igpu
└───src  <-------- kodingan dan entry point
```

## Cara compile
Untuk sekarang disarankan menggunakan `build.ps1` yang sudah ada di root folder repo ini. 
Pastikan sudah memiliki gcc / g++ 64bit dan menggunakan standar c++ 11 keatas. 
Setelah berhasil compile, executable akan disimpan di `bin/main.exe`

jika tidak bisa melakukan run ps1 file tersebut dikarenakan permission atau keamanan run unknown script run dalam powershell admin
```
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned
```

## Pemecahan kode ke file
### entar dulu
