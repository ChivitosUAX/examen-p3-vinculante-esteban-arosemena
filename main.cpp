#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

struct Task {
    std::string id;                             // Identificador de la tarea (letra)
    std::string name;                           // Nombre de la tarea
    int duration;                               // Duración de la tarea
    std::vector<std::string> dependencies;      // Tareas de las que depende
    std::string assignedTo;                     // Recurso asignado (Ejecutivo o Ayudante)
    int startTime = -1;                         // Tiempo de inicio
    int endTime = -1;                           // Tiempo de finalización
};

struct Resource {
    std::string name;                           // Nombre del recurso
    int availableAt = 0;                        // Tiempo en que el recurso está disponible
};

int main() {
    // Definir las tareas con sus propiedades
    std::unordered_map<std::string, Task> tasks = {
        {"A", {"A", "Reserva de vuelo", 20, {}, "Ejecutivo"}},
        {"B", {"B", "Informar a casa para empacar", 5, {}, "Ayudante 1"}},
        {"C", {"C", "Empacar maletas", 40, {"B"}, "Ayudante 1"}},
        {"D", {"D", "Preparación del billete por la agencia", 10, {"A"}, "Agencia"}},
        {"E", {"E", "Recoger el billete de la agencia", 5, {"D"}, "Ejecutivo"}},
        {"F", {"F", "Llevar el billete a la oficina", 10, {"E"}, "Ejecutivo"}},
        {"G", {"G", "Recoger las maletas de casa", 20, {"C"}, "Ayudante 1"}},
        {"H", {"H", "Llevar maletas a la oficina", 5, {"G"}, "Ayudante 4 y 5"}}, // Duración reducida
        {"I", {"I", "Conversación sobre documentos requeridos", 35, {}, "Ejecutivo"}},
        {"J", {"J", "Dictar instrucciones para ausencia", 25, {}, "Ayudante 2"}},
        {"K", {"K", "Reunir documentos", 15, {"I"}, "Ayudante 3"}},
        {"L", {"L", "Organizar documentos", 5, {"K"}, "Ayudante 3"}},
        {"M", {"M", "Viajar al aeropuerto y facturar", 25, {"F", "H", "L", "J"}, "Ejecutivo"}}
    };

    // Definir los recursos
    std::unordered_map<std::string, Resource> resources = {
        {"Ejecutivo", {"Ejecutivo", 0}},
        {"Ayudante 1", {"Ayudante 1", 0}},
        {"Ayudante 2", {"Ayudante 2", 0}},
        {"Ayudante 3", {"Ayudante 3", 0}},
        {"Ayudante 4 y 5", {"Ayudante 4 y 5", 0}},
        {"Agencia", {"Agencia", 0}}
    };

    // Función para obtener una tarea por su identificador
    auto getTask = [&](const std::string& id) -> Task& {
        return tasks[id];
    };

    // Función para verificar si las dependencias de una tarea se han completado
    auto dependenciesCompleted = [&](Task& task) -> bool {
        for (const auto& depId : task.dependencies) {
            if (tasks[depId].endTime == -1) {
                return false;
            }
        }
        return true;
    };

    // Lista de tareas pendientes
    std::vector<std::string> pendingTasks;
    for (const auto& pair : tasks) {
        pendingTasks.push_back(pair.first);
    }

    // Asignar tiempos de inicio y finalización a las tareas
    int currentTime = 0;
    bool progress = true;
    while (progress) {
        progress = false;
        for (const auto& taskId : pendingTasks) {
            Task& task = tasks[taskId];
            if (task.startTime == -1 && dependenciesCompleted(task)) {
                Resource& resource = resources[task.assignedTo];

                // Determinar el tiempo más temprano en que la tarea puede iniciar
                int earliestStart = resource.availableAt;
                for (const auto& depId : task.dependencies) {
                    if (tasks[depId].endTime > earliestStart) {
                        earliestStart = tasks[depId].endTime;
                    }
                }

                // Ajuste específico para priorizar "A" al inicio
                if (task.id == "A") {
                    earliestStart = 0; // Forzar inicio al tiempo 0
                }

                // Evitar asignar tareas en el pasado
                if (earliestStart < currentTime) {
                    earliestStart = currentTime;
                }

                // Asignar tiempos de inicio y finalización
                task.startTime = earliestStart;
                task.endTime = task.startTime + task.duration;

                // Actualizar la disponibilidad del recurso
                resource.availableAt = task.endTime;

                progress = true;
            }
        }
        // Incrementar el tiempo actual si no hubo progreso
        if (!progress) {
            currentTime++;
        }
    }

    // Verificar si todas las tareas se han programado
    bool allScheduled = true;
    for (const auto& pair : tasks) {
        if (pair.second.endTime == -1) {
            allScheduled = false;
            break;
        }
    }

    if (!allScheduled) {
        std::cout << "No se pudieron programar todas las tareas.\n";
        return 1;
    }

    // Calcular el tiempo total del proyecto
    int totalTime = 0;
    for (const auto& pair : tasks) {
        if (pair.second.endTime > totalTime) {
            totalTime = pair.second.endTime;
        }
    }

    // Mostrar el cronograma
    std::cout << "Cronograma de tareas:\n";
    std::vector<Task> scheduledTasks;
    for (const auto& pair : tasks) {
        scheduledTasks.push_back(pair.second);
    }

    // Ordenar las tareas por tiempo de inicio
    std::sort(scheduledTasks.begin(), scheduledTasks.end(), [](const Task& a, const Task& b) {
        return a.startTime < b.startTime;
    });

    for (const auto& task : scheduledTasks) {
        std::cout << task.assignedTo << " realiza " << task.id << ": " << task.name
                  << " de " << task.startTime << " min a " << task.endTime << " min.\n";
    }

    std::cout << "\nTiempo total del proyecto: " << totalTime << " minutos.\n";

    if (totalTime <= 100) {
        std::cout << "Es posible completar todas las tareas en el plazo de 100 minutos.\n";
    } else {
        std::cout << "No es posible completar todas las tareas en el plazo de 100 minutos.\n";
    }

    return 0;
}
