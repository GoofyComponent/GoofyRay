//
// Created by dev-tgamiette on 28/10/2024.
//

#include "../hittable.h"  // Inclut la classe de base 'hittable' dont 'sphere' hérite

class sphere : public hittable {  // La classe 'sphere' hérite de 'hittable'
private:
    Vector center;  // Centre de la sphère dans l'espace 3D
    float radius;   // Rayon de la sphère

public:
    sphere();

    ~sphere() override;

    // Méthode statique pour calculer le produit scalaire entre deux vecteurs
    static float dot(const Vector &vector, const Vector &oc) {
        return vector.X() * oc.X() + vector.Y() * oc.Y() + vector.Z() * oc.Z();
    }

    bool hit(Ray ray, double tMin, double tMax, hit_record &rec) {
        Vector oc = center - ray.origin();

        // Coefficient 'a' dans l'équation quadratique, égale au carré de la longueur de la direction du rayon
        auto a = ray.direction().length_squared();

        // Coefficient 'h' dans l'équation quadratique, représentant la projection de 'oc' sur la direction du rayon
        auto h = dot(ray.direction(), oc);

        // Coefficient 'c' dans l'équation quadratique, qui dépend du carré du rayon de la sphère
        auto c = oc.length_squared() - radius * radius;

        // Calcul du discriminant, qui détermine si le rayon touche ou non la sphère
        auto discriminant = h * h - a * c;
        if (discriminant < 0)  // Si le discriminant est négatif, pas d'intersection
            return false;

        // Calcul de la racine carrée du discriminant pour trouver les solutions
        discriminant = sqrt(discriminant);

        // Calcul des deux solutions de l'équation quadratique
        const double t1 = (-h - discriminant) / a;  // Première solution
        const double t2 = (-h + discriminant) / a;  // Deuxième solution

        // Vérifie si les solutions sont en dehors de la plage d'intersection [tMin, tMax]
        if (t1 > tMax || t2 < tMin)
            return false;

        // Met à jour tMin et tMax pour la valeur valide
        if (t1 < tMin)
            tMin = t1;
        if (t2 > tMax)
            tMax = t2;

        // Enregistre les informations de l'intersection dans 'rec'
        rec.t = tMin;
        rec.p = ray.origin() + tMin * ray.direction();  // Point d'intersection
        rec.normal = (rec.p - center) / radius;  // Calcul de la normale au point d'intersection

        return true;  // Le rayon touche la sphère
    }
};
