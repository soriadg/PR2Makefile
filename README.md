# Proyecto PR2Makefile: Automatización con Makefiles

Este proyecto tiene como objetivo demostrar el dominio de la estructura y funcionalidad de un **Makefile** aplicado a un generador de patrones matemáticos (Fractales de Mandelbrot y Sierpinski) en C++.

---

## 1. Explicación del Proyecto
El proyecto consiste en una aplicación de consola que genera imágenes en formato `.ppm`. Utiliza algoritmos matemáticos para renderizar:
*   **Conjunto de Mandelbrot:** Un fractal definido en el plano complejo.
*   **Triángulo de Sierpinski:** Generado mediante el algoritmo de "Chaos Game".

La complejidad del proyecto radica en la gestión de múltiples archivos fuente (`main.cpp`, `mandelbrot.cpp`, `sierpinski.cpp`) y sus dependencias, lo cual justifica el uso de un Makefile para automatizar su construcción.

---

## 2. Análisis del Makefile
El `Makefile` actúa como un guion de compilación que estandariza el proceso. A continuación se explica su funcionamiento detallado:

### Variables (Estandarización)
*   `CXX = g++`: Define el compilador. 
*   `CXXFLAGS`: Define los parámetros de calidad y optimización.
*   `OBJ_DIR`, `SRC_DIR`, `OUTPUT_DIR`: Organizan el proyecto en carpetas.

### Reglas y Automatización
1.  **Compilación Incremental:** Solo se recompilan los archivos modificados.
2.  **Gestión de Directorios:** El Makefile crea las carpetas `obj/` y `output/` automáticamente.
3.  **Encadenamiento de Comandos:** Verifica dependencias antes de ejecutar.

---

## 3. Instrucciones de Ejecución
Sigue estos pasos en tu terminal:

1.  **Limpiar archivos previos:**
```text
make clean
```
2.  **Compilar el proyecto completo:**
```text
make
```
3.  **Generar el Fractal de Mandelbrot:**
```text
make run_mandelbrot
```
4.  **Generar el Triángulo de Sierpinski:**
```text
make run_sierpinski
```

---

## 4. Reporte de Resultados de Ejecución
Al ejecutar los comandos, se obtuvo el siguiente comportamiento:

```text
$ make
mkdir -p obj
g++ -O3 -Wall -Wextra -Iinclude -std=c++11 -c -o obj/main.o src/main.cpp
g++ -O3 -Wall -Wextra -Iinclude -std=c++11 -c -o obj/mandelbrot.o src/mandelbrot.cpp
g++ -O3 -Wall -Wextra -Iinclude -std=c++11 -c -o obj/sierpinski.o src/sierpinski.cpp
g++ -O3 -Wall -Wextra -Iinclude -std=c++11 -o pattern_gen obj/main.o obj/mandelbrot.o obj/sierpinski.o

$ make run_mandelbrot
./pattern_gen mandelbrot
Generating Mandelbrot Set...
Created output/mandelbrot.ppm
```

**Resultado:** Se generaron exitosamente los archivos en la carpeta `output/`.

---

## 5. Conclusiones sobre la Automatización
El uso de este Makefile permite que cualquier desarrollador pueda replicar el proyecto con exactitud, garantizando que el entorno de desarrollo sea consistente y libre de errores manuales.

---
