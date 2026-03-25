| Algo                               | Complexité moyenne               | Points forts                           | Points faibles                      | Quand l’utiliser                 |
| ---------------------------------- | -------------------------------- | -------------------------------------- | ----------------------------------- | -------------------------------- |
| **Bubble Sort**                    | O(n²)                            | Très simple, facile à coder            | Très lent pour gros tableaux        | Petits tableaux, pédagogie       |
| **Insertion Sort**                 | O(n²)                            | Bon sur tableaux presque triés, stable | Mauvais sur gros tableaux           | Tri partiel ou quasi trié        |
| **Selection Sort**                 | O(n²)                            | Simple, prévisible                     | Pas stable, lent                    | Petits tableaux, simplicité      |
| **Merge Sort**                     | O(n log n)                       | Stable, rapide, diviser pour régner    | Besoin de mémoire supplémentaire    | Tableaux moyens à grands         |
| **Quick Sort**                     | O(n log n) moyen, O(n²) pire cas | Très rapide, en place                  | Pire cas possible si mauvais pivot  | Tableaux grands et variés        |
| **Heap Sort**                      | O(n log n)                       | En place, fiable                       | Plus complexe à coder               | Quand tu veux O(n log n) garanti |
| **Counting / Radix / Bucket Sort** | O(n + k)                         | Ultra rapide pour entiers limités      | Spécialisé, dépend de la valeur max | Gros tableaux d’entiers ou clés  |
