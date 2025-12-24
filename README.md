# 🔬 Langages-Programmation-Systeme

Ce dépôt regroupe une série d'études pratiques portant sur les concepts fondamentaux de l'informatique système. L'objectif est d'analyser l'impact des choix d'implémentation (mémoire, portée, liaison) sur les performances et le comportement des logiciels à travers différents langages (C++, Java, Perl).

## 📂 Contenu du Laboratoire

### 1. Portée Statique vs Dynamique (Perl)
* **Fichier** : `programme1.pl`
* **Concept** : Analyse de la visibilité des variables. 
* **Démonstration** : Comparaison entre la **portée lexicale** (`my`), qui limite la variable au bloc local, et la **portée dynamique** (`local`), qui propage la modification aux fonctions imbriquées.

### 2. Performance de l'Allocation Mémoire (C++)
* **Fichier** : `programme2.cpp`
* **Concept** : Mesure du temps d'exécution pour trois types d'allocation : **statique**, sur la **pile** (stack) et **dynamique** (heap).
* **Analyse** : Étude de la rapidité d'accès pour un tableau de 1 000 000 d'éléments et impact des optimisations du compilateur (`-O2`).



### 3. Liaisons Statique vs Dynamique (C++)
* **Fichiers** : `programme3.cpp` & `programme4.cpp`
* **Concept** : Étude du polymorphisme et des fonctions virtuelles.
* **Démonstration** : 
    * Le `programme3` mesure le coût d'appel d'une fonction virtuelle.
    * Le `programme4` illustre la hiérarchie de classes (A → B → C) et l'utilisation de la **VTable** (Table Virtuelle).

### 4. Concurrence : Lecteurs-Rédacteurs (Java)
* **Fichier** : `programme5.java`
* **Concept** : Gestion des accès concurrents à une ressource partagée.
* **Solution** : Utilisation de `ReentrantReadWriteLock` pour permettre des lectures simultanées tout en garantissant un accès exclusif aux rédacteurs.



## 📝 Rapport d'Analyse
Le document **Rapport.docx** fournit une discussion approfondie, les mesures chronométrées précises et les conclusions théoriques pour chaque problématique traitée.

## 🛠️ Instructions d'Exécution

| Langage | Commande de Compilation / Exécution |
| :--- | :--- |
| **Perl** | `perl programme1.pl` |
| **C++** | `g++ programmeX.cpp -O2 -o progX` suivi de `./progX` |
| **Java** | `javac programme5.java` suivi de `java programme5` |


