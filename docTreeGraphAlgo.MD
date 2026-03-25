1️⃣ Liste exhaustive des algorithmes sur arbres
Parcours
DFS (Depth First Search)
Préfixe (pre-order) : Node → Left → Right
Infixe (in-order) : Left → Node → Right
Utile pour obtenir des valeurs triées dans un BST
Postfixe (post-order) : Left → Right → Node
Utile pour libérer mémoire, évaluation d’expressions
BFS / Niveau par niveau
Queue → parcours niveau par niveau
Utile pour plus court chemin dans arbre non pondéré, recherche globale
Spécifiques aux BST
Insertion
Suppression
Recherche
Vérification d’équilibre (AVL)
Rotations pour arbres équilibrés (AVL, Red-Black)
Arbres particuliers
AVL Tree → BST auto-équilibré
Red-Black Tree → BST avec règles couleurs pour garantir hauteur log(n)
Heap → Max-heap / Min-heap, utilisé pour file de priorité
Segment Tree → pour intervalles et requêtes rapides
Fenwick Tree (Binary Indexed Tree) → pour sommes cumulées
2️⃣ Liste exhaustive des algorithmes sur graphes
Parcours
DFS (Depth First Search)
BFS (Breadth First Search)
Dijkstra → plus court chemin (graphe pondéré positif)
Bellman-Ford → plus court chemin (graphe avec poids négatifs)
Floyd-Warshall → plus court chemin entre tous les couples
A* → heuristique + Dijkstra, pour pathfinding optimisé
Détection / Structure
Cycle detection (DFS + parent / Union-Find)
Topological sort (DAG)
Connected components (DFS/BFS)
Strongly Connected Components (Kosaraju, Tarjan)
Minimum Spanning Tree (MST)
Kruskal
Prim
Maximum flow / Min-cut (Ford-Fulkerson, Edmonds-Karp)
Algorithmes spécifiques
BFS/DFS modifié → bridges, articulation points
Graph coloring
Traveling Salesman Problem (TSP) heuristics
Network routing algorithms (OSPF, Dijkstra appliqué)
✅ Bonus méthodo
Arbres → bonne structure pour recherche, tri, hiérarchie
Graphes → bonne structure pour connexion, réseaux, dépendances

| Algo / Structure            | Type             | Complexité (moyenne) | Cas d’usage / Notes                                                            |
| --------------------------- | ---------------- | -------------------- | ------------------------------------------------------------------------------ |
| **DFS (pre/in/post-order)** | Parcours         | O(n)                 | Préfixe : copie / expression; Infixe : BST trié; Postfixe : libération mémoire |
| **BFS / niveau**            | Parcours         | O(n)                 | Recherche niveau par niveau, plus court chemin non pondéré                     |
| **BST insertion**           | BST              | O(log n)             | Ajout de valeur dans arbre de recherche                                        |
| **BST recherche**           | BST              | O(log n)             | Chercher valeur dans arbre trié                                                |
| **BST suppression**         | BST              | O(log n)             | Supprimer un noeud tout en conservant BST                                      |
| **AVL Tree**                | BST équilibré    | O(log n)             | Auto-équilibré pour garantir recherche rapide                                  |
| **Red-Black Tree**          | BST équilibré    | O(log n)             | Stockage efficace, utilisé dans std::map / std::set                            |
| **Heap (Max/Min)**          | Arbre complet    | O(log n)             | File de priorité, tri par heap                                                 |
| **Segment Tree**            | Arbre spécialisé | O(log n)             | Requêtes sur intervalles, update rapide                                        |
| **Fenwick Tree (BIT)**      | Arbre spécialisé | O(log n)             | Sommes cumulées, update rapide                                                 |
| **Rotations (AVL / RB)**    | Equilibrage      | O(1)                 | Maintenir arbre équilibré après insertion/suppression                          |


| Algo / Structure                        | Type                | Complexité        | Cas d’usage / Notes                               |
| --------------------------------------- | ------------------- | ----------------- | ------------------------------------------------- |
| **DFS (Depth First Search)**            | Parcours            | O(V + E)          | Exploration complète, détection cycles            |
| **BFS (Breadth First Search)**          | Parcours            | O(V + E)          | Plus court chemin non pondéré, exploration niveau |
| **Dijkstra**                            | Plus court chemin   | O(E log V)        | Graphe pondéré, poids positifs                    |
| **Bellman-Ford**                        | Plus court chemin   | O(VE)             | Poids négatifs possibles                          |
| **Floyd-Warshall**                      | Tous-pairs shortest | O(V³)             | Plus court chemin entre tous les couples          |
| **A***                                  | Plus court chemin   | O(E) / O(V log V) | Pathfinding avec heuristique (jeu, robotique)     |
| **Cycle Detection**                     | Analyse             | O(V + E)          | Détecter cycles dans graphe orienté/non-orienté   |
| **Topological Sort**                    | DAG                 | O(V + E)          | Ordonnancement de tâches, dépendances             |
| **Connected Components**                | Analyse             | O(V + E)          | Trouver composantes connexes                      |
| **Strongly Connected Components (SCC)** | Analyse             | O(V + E)          | Graphe orienté, Tarjan/Kosaraju                   |
| **Minimum Spanning Tree**               | MST                 | O(E log V)        | Kruskal / Prim, réseau efficace                   |
| **Max Flow / Min Cut**                  | Flow                | O(V * E²)         | Optimisation flux réseau                          |
| **Graph Coloring**                      | Analyse             | NP-complet        | Assignation ressources sans conflit               |
| **TSP heuristics**                      | Optimisation        | NP-complet        | Voyageur de commerce, approximation               |
