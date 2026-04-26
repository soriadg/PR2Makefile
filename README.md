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
*   `CXX = g++`: Define el compilador. Cambiar de compilador es tan fácil como editar esta línea.
*   `CXXFLAGS`: Define los parámetros de calidad y optimización (`-O3` para velocidad, `-Wall` para detectar errores).
*   `OBJ_DIR`, `SRC_DIR`, `OUTPUT_DIR`: Organizan el proyecto en carpetas, manteniendo la raíz limpia.

### Reglas y Automatización
1.  **Compilación Incremental:** La regla `$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp` permite que solo se recompilen los archivos que han sido modificados, ahorrando tiempo.
2.  **Gestión de Directorios:** El Makefile verifica la existencia de las carpetas `obj/` y `output/`, creándolas automáticamente si no existen (`mkdir -p`).
3.  **Encadenamiento de Comandos:** Al ejecutar un objetivo como `run_mandelbrot`, el Makefile verifica primero si el ejecutable está actualizado; si no, lo compila antes de correr el programa.

---

## 3. Instrucciones de Ejecución
Sigue estos pasos en tu terminal:

1.  **Limpiar archivos previos:**
    ```bash
    make clean
    ```
2.  **Compilar el proyecto completo:**
    ```bash
    make
    ```
3.  **Generar el Fractal de Mandelbrot:**
    ```bash
    make run_mandelbrot
    ```
4.  **Generar el Triángulo de Sierpinski:**
    ```bash
    make run_sierpinski
    ```

---

## 4. Reporte de Resultados de Ejecución
Al ejecutar los comandos anteriores, se obtuvo el siguiente comportamiento automatizado:

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

**Resultado:** Se generaron exitosamente dos archivos de imagen en la carpeta `output/`:
*   `mandelbrot.ppm` (~5.1 MB)
*   `sierpinski.ppm` (~7.5 MB)

---

## 5. Conclusiones sobre la Automatización
El uso de este Makefile permite que cualquier desarrollador, sin conocer los comandos exactos de `g++`, pueda replicar el proyecto con exactitud. Además, garantiza que el entorno de desarrollo sea consistente, evitando el clásico error de "en mi máquina sí funciona" al forzar los mismos flags y rutas de salida para todos.

---
*Documentación creada por soriadg para la asignatura de IoT.*
