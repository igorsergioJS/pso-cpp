#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// Função objetivo
double objective_function(double x, double y) {
    double r1 = pow(y - pow(x, 2), 2) + pow(1 - x, 2);
    double z = -x * sin(sqrt(fabs(x))) - y * sin(sqrt(fabs(y)));
    double w15 = z * exp(cos(r1));
    return w15;
}

// Função PSO
std::pair<std::vector<double>, double> pso(int num_particles, int num_iterations, const std::vector<std::pair<double, double>>& bounds, 
                                           double inertia, double cognitive, double social) {
    int dim = bounds.size();
    std::vector<std::vector<double>> particles(num_particles, std::vector<double>(dim));
    std::vector<std::vector<double>> velocities(num_particles, std::vector<double>(dim, 0.1));
    std::vector<std::vector<double>> personal_best_positions = particles;
    std::vector<double> personal_best_scores(num_particles);
    
    // Inicialização de partículas e limites
    srand(time(0));
    for (int i = 0; i < num_particles; i++) {
        for (int d = 0; d < dim; d++) {
            particles[i][d] = bounds[d].first + ((double)rand() / RAND_MAX) * (bounds[d].second - bounds[d].first);
        }
        personal_best_scores[i] = objective_function(particles[i][0], particles[i][1]);
        personal_best_positions[i] = particles[i];
    }
    
    // Definição do melhor global
    std::vector<double> global_best_position = personal_best_positions[0];
    double global_best_score = personal_best_scores[0];
    for (int i = 1; i < num_particles; i++) {
        if (personal_best_scores[i] < global_best_score) {
            global_best_score = personal_best_scores[i];
            global_best_position = personal_best_positions[i];
        }
    }

    // Loop de iterações do PSO
    for (int t = 0; t < num_iterations; t++) {
        for (int i = 0; i < num_particles; i++) {
            for (int d = 0; d < dim; d++) {
                velocities[i][d] = inertia * velocities[i][d] +
                                   cognitive * ((double)rand() / RAND_MAX) * (personal_best_positions[i][d] - particles[i][d]) +
                                   social * ((double)rand() / RAND_MAX) * (global_best_position[d] - particles[i][d]);
                
                particles[i][d] += velocities[i][d];

                // Respeitar os limites
                if (particles[i][d] < bounds[d].first) particles[i][d] = bounds[d].first;
                if (particles[i][d] > bounds[d].second) particles[i][d] = bounds[d].second;
            }

            double score = objective_function(particles[i][0], particles[i][1]);
            if (score < personal_best_scores[i]) {
                personal_best_scores[i] = score;
                personal_best_positions[i] = particles[i];
            }
        }

        for (int i = 0; i < num_particles; i++) {
            if (personal_best_scores[i] < global_best_score) {
                global_best_score = personal_best_scores[i];
                global_best_position = personal_best_positions[i];
            }
        }
    }

    return {global_best_position, global_best_score};
}

int main() {
    // Parâmetros do PSO
    int num_particles = 30000;
    int num_iterations = 500;
    std::vector<std::pair<double, double>> bounds = {{-100000, 100000}, {-100000, 100000}}; // Limites para x e y
    double inertia = 0.5;
    double cognitive = 1.5;
    double social = 1.5;

    // Execução
    std::pair<std::vector<double>, double> result = pso(num_particles, num_iterations, bounds, inertia, cognitive, social);
    std::vector<double> best_position = result.first;
    double best_score = result.second;
    
    // Resultados
    std::cout << "Best Position: (" << best_position[0] << ", " << best_position[1] << ")\n";
    std::cout << "Best Score (w15): " << best_score << std::endl;

    return 0;
}
