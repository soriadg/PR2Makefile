# Tarea de Makefile

Makefile para un programa en C++ que genera dos fractales: Mandelbrot y Sierpinski. El código está repartido en tres archivos fuente (main.cpp, mandelbrot.cpp, sierpinski.cpp) con sus respectivas cabeceras.

---

## Para qué sirve un Makefile?

Un Makefile automatiza la compilación de un proyecto. En vez de ejecutar manualmente cada comando de compilación, define las reglas una sola vez y `make` se encarga del resto.

**Ventajas:**

- **Compilación incremental:** solo recompila los archivos que cambiaron. En proyectos grandes esto ahorra tiempo significativo.
- **Estandarización:** cualquier persona que clone el repo compila el proyecto exactamente igual, con los mismos flags y rutas, sin tener que adivinar nada.
- **Automatización:** una sola instrucción puede compilar, crear directorios, ejecutar pruebas o limpiar el proyecto.
- **Manejo de dependencias:** make conoce la relación entre archivos y decide por sí solo qué necesita reconstruir.

**Aplicaciones comunes:**

- Compilación de proyectos en C y C++
- Sistemas embebidos e IoT (toolchains de ARM, AVR, etc.)
- Generación automática de documentación (Doxygen, LaTeX)
- Automatización de pruebas y despliegues
- Cualquier flujo de trabajo donde haya pasos repetitivos que dependan unos de otros

---

## Flujo del Makefile

```
make  →  all  →  pattern_gen  →  obj/  →  output/
```

**make** — Lee las variables, crea la carpeta obj si falta, compila cada fuente en su archivo objeto y enlaza los tres en pattern_gen. Si un objeto ya está al día respecto a su fuente, lo deja igual y solo vuelve a enlazar.

**make run_mandelbrot / make run_sierpinski** — Verifican que el ejecutable esté actualizado, crean la carpeta output si hace falta y lanzan el programa con el argumento correspondiente.

**make clean** — Elimina los archivos objeto, el ejecutable y las imágenes generadas.

---

## Compilación

```bash
make clean
make
make run_mandelbrot
make run_sierpinski
```

---

## Output

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

$ make clean
rm -rf obj pattern_gen output/*.ppm
```

Salidas en output/: mandelbrot.ppm (~5.1 MB) y sierpinski.ppm (~7.5 MB).

---

*soriadg — IoT*
