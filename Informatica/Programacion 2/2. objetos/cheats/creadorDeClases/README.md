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
- **Modular y Limpio:** Código organizado en paquetes para fácil mantenimiento.

---

## 📂 Estructura del Proyecto

El código está organizado de la siguiente manera:

- `GeneradorDeClases.java`: Punto de entrada del programa (Raíz).
- `modelo/`: Definición de las entidades base (`Clase`, `Variable`, `Elemento`).
- `servicio/`: Lógica de negocio, creación de clases y el motor de `GeneradorDeCodigo`.
- `persistencia/`: Gestión de guardado, carga de sesión y lectura de archivos físicos.
- `ui/`: Componentes de interfaz de usuario, menús y estilos ANSI.
- `util/`: Utilidades de formateo, validaciones y clase centralizada de `Config`.

---

## 🚀 Requisitos e Instalación

### Requisitos
- **Java SDK 23** o superior.
- Una terminal con soporte para colores ANSI (VS Code, PowerShell, Terminal de Linux/Mac).

### Instalación
1. Descarga o clona este repositorio.
2. Abre una terminal en la carpeta raíz del proyecto.

---

## 📖 Guía de Uso Rápido

1. **Crear una Clase:** Selecciona la opción `1`. Ingresa el nombre. Si es abstracta, podrás definir métodos abstractos.
2. **Agregar Variables:** El programa te guiará. Si el tipo termina en `[]` (ej: `Persona[]`), se activará el **Modo Vector** pidiéndote un tamaño máximo.
3. **Guardar:** Las clases se exportan automáticamente a la carpeta `/generadas`.
4. **Sincronizar (Opción S):** Si borras un archivo de la carpeta o agregas uno nuevo manualmente, usa esta opción para que la memoria del programa coincida con el disco.
5. **Revisiones (Opción R):** Si modificas un archivo `.java` en `/generadas`, el programa detectará cambios externos en la subcarpeta `generadas/revisiones` y te permitirá previsualizarlos.

---

## ⚠️ Notas Importantes
- **Carpeta `generadas/`:** Es el lugar donde vive tu código generado.
- **Subcarpeta `generadas/revisiones/`:** Aquí se almacenan temporalmente las versiones modificadas externamente para ser confirmadas.
- **Archivo `memoria.dat`:** Ubicado en `/generadas`. Es donde el programa guarda tu sesión. Si lo borras, perderás el historial de clases cargadas en el menú.

---
*Desarrollado para facilitar el aprendizaje de POO en la UNLP.* 🎓
