# Mini-projet A : répartition du travail (proposition)

## Qui fait quoi

| Étudiant | Nom | Code | Rapport | Relit le code de |
|---|---|---|---|---|
| **A** : socle + S1 | ______ | `etudiant.h/.c` (struct, moyenne, génération aléatoire), liste non triée, tri rapide, top-k | Présentation, S1 | B |
| **B** : S2 + menu | ______ | Tableau trié, insertion, dichotomie, comptage des moyennes égales, suppression, top-k, `main.c` | S2 | C |
| **C** : S3 | ______ | ABR, doublons, suppression (3 cas), parcours croissant et décroissant, libération mémoire | S3 | D |
| **D** : expérimentation | ______ | Chronométrage avec `clock()`, répétitions, jeux meilleur/pire cas, export des données, gnuplot | Protocole, courbes, synthèse | A |

L'analyse et la conclusion se rédigent à quatre. Chacun fournit les complexités et les cas meilleur/pire de sa structure.

## À décider ensemble le premier jour

1. **Interfaces `.h`** : mêmes opérations pour les trois structures (`ajouter`, `rechercher`, `supprimer`, `afficher`, `topk`, `liberer`).
2. **Clé** : notes en centièmes (entiers), leur somme sert de clé exacte. Pas de `==` entre `float`.
3. **Doublons dans l'ABR** : liste par nœud, ou doublons à droite ? Avec une liste par nœud, la hauteur est limitée au nombre de moyennes distinctes (10 001 au maximum en centièmes).
4. **Mémoire** : tableau de structures ou de pointeurs ?
5. **S1** : coder tableau et liste chaînée pour comparer les deux par des mesures ?

## Planning (3 semaines)

- **Semaine 1** : interfaces, module étudiant (en priorité), ajout, recherche, affichage.
- **Semaine 2** : suppression, top-k, intégration, tests mémoire (Valgrind ou `-fsanitize=address`), premières mesures.
- **Semaine 3** : mesures finales, rapport, répétition de la soutenance. Bonus seulement si la base est terminée.

Chaque fin de semaine : une heure où chacun explique le code qu'il a relu (l'oral comporte des questions individuelles sur tout le code).

## Règles Git

- Une branche par tâche, fusionnée par Pull Request après relecture.
- Rien n'est poussé directement sur `main` après le squelette.
- Rien n'est fusionné s'il ne compile pas avec `gcc -Wall -Wextra`.
- Prévenir le responsable avant de modifier son fichier.
- Jamais de `git push --force`.
