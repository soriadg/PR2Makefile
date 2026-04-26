# Proyecto PR2: Automatización con Makefile

Este proyecto genera fractales (Mandelbrot y Sierpinski) usando C++ y automatiza todo el proceso con un Makefile.

## ¿Qué hace el Makefile?
El Makefile es el archivo que se encarga de compilar todo el código automáticamente. Sus ventajas son:
1. No tienes que escribir comandos largos de g++ cada vez.
2. Solo compila los archivos que cambiaste (ahorra tiempo).
3. Crea las carpetas necesarias (obj y output) el solo.

## Instrucciones para usarlo

Para compilar el programa desde cero:
```bash
make clean
make
```

Para generar los fractales:
```bash
make run_mandelbrot
make run_sierpinski
```

## Resultados
Al ejecutarlo, el Makefile compila los archivos .cpp en la carpeta src, genera archivos .o en la carpeta obj y finalmente crea el ejecutable pattern_gen. Las imágenes resultantes se guardan en la carpeta output como archivos .ppm.

Este sistema asegura que cualquier persona pueda correr el código sin errores de compilación manual.

---
*Hecho por soriadg*
