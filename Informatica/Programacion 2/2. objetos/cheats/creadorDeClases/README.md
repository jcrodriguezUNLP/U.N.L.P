# Java Class Generator 3.0 🚀

Un potente generador de código Java para la terminal, diseñado específicamente para estudiantes de Programación Orientada a Objetos (POO). Permite modelar clases, gestionar herencia, colecciones (Listas/Arrays) y sincronizar cambios bidireccionalmente entre la memoria del programa y tus archivos `.java`.

---

## ✨ Características Principales

- **Modelado Visual:** Crea clases con variables propias y heredadas.
- **Soporte de Vectores:** Genera automáticamente lógica de Dimensión Lógica, Física y métodos `agregar/eliminar` al detectar arrays.
- **Herencia Avanzada:** Gestiona cadenas de herencia y detecta ciclos de herencia prohibidos.
- **Sincronización Inteligente:** 
  - **Importar:** Lee archivos `.java` existentes y los convierte en objetos.
  - **Revisiones:** Si editas un archivo manualmente, el programa detecta el cambio y te ofrece actualizar la memoria.
- **Modular y Limpio:** Código organizado en capas técnicas para fácil mantenimiento.

---

## 📂 Estructura del Proyecto

El código está organizado siguiendo una arquitectura de capas:

- `core/`: Punto de entrada (`GeneradorDeClases.java`).
- `modelo/`: Definición de datos (`Clase`, `Variable`, `Elemento`).
- `servicio/`: Lógica de negocio y generación de código (`GeneradorDeCodigo`, `CrearClase`).
- `persistencia/`: Gestión de archivos físicos y binarios.
- `ui/`: Interfaz de usuario por consola y estilos ANSI.
- `util/`: Herramientas auxiliares de validación y formateo.

---

## 🚀 Requisitos e Instalación

### Requisitos
- **Java SDK 23** o superior.
- Una terminal con soporte para colores ANSI (VS Code, PowerShell, Terminal de Linux/Mac).

### Instalación
1. Descarga o clona este repositorio.
2. Abre una terminal en la carpeta raíz del proyecto.

---

## 🛠️ Compilación y Ejecución

Debido a la estructura de paquetes, se recomienda compilar hacia un directorio `bin`:

### En Windows (PowerShell)
```powershell
# 1. Crear carpeta bin si no existe
if (!(Test-Path bin)) { mkdir bin }

# 2. Compilar todo el proyecto
javac -d bin -sourcepath . core/GeneradorDeClases.java

# 3. Ejecutar
java -cp bin core.GeneradorDeClases
```

### En Linux / Mac
```bash
mkdir -p bin
javac -d bin -sourcepath . core/GeneradorDeClases.java
java -cp bin core.GeneradorDeClases
```

---

## 📖 Guía de Uso Rápido

1. **Crear una Clase:** Selecciona la opción `1`. Ingresa el nombre. Si es abstracta, podrás definir métodos abstractos.
2. **Agregar Variables:** El programa te guiará. Si el tipo termina en `[]` (ej: `Persona[]`), se activará el **Modo Vector** pidiéndote un tamaño máximo.
3. **Guardar:** Las clases se exportan automáticamente a la carpeta `/generadas`.
4. **Sincronizar (Opción S):** Si borras un archivo de la carpeta o agregas uno nuevo manualmente, usa esta opción para que la memoria del programa coincida con el disco.
5. **Revisiones (Opción R):** Si modificas un archivo `.java` en `/generadas` (ej: cambias un tipo de dato), el programa lo detectará como una "Revisión Pendiente" y te permitirá ver los cambios antes de aceptarlos.

---

## ⚠️ Notas Importantes
- **Carpeta `generadas/`:** Es el lugar donde vive tu código. No cambies el nombre de esta carpeta.
- **Archivo `memoria.dat`:** Es donde el programa guarda tu sesión. Si lo borras, perderás el historial de clases en el menú (aunque los archivos `.java` seguirán existiendo).

---
*Desarrollado para facilitar el aprendizaje de POO en la UNLP.* 🎓
