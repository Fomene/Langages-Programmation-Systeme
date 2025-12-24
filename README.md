# 🔬 Laboratoire : Concepts Fondamentaux des Langages de Programmation

[cite_start]Ce projet regroupe une série d'expérimentations pratiques visant à analyser les mécanismes internes de gestion de la mémoire, de portée et de concurrence dans différents langages de programmation[cite: 85, 86].

## 📂 Contenu du Dépôt

### 1. Portée Statique vs Dynamique (Perl)
* [cite_start]**Fichier** : `programme1.pl` [cite: 3]
* [cite_start]**Concept** : Comparaison entre la portée lexicale (`my`) et la portée dynamique (`local`)[cite: 2, 3].
* [cite_start]**Observation** : Le programme démontre comment `my` masque la variable globale localement tandis que `local` la réassigne temporairement pour toute la chaîne d'appels[cite: 5, 6].

### 2. Comparaison d'Allocation Mémoire (C++)
* [cite_start]**Fichier** : `programme2.cpp` [cite: 14]
* [cite_start]**Concept** : Mesure du temps d'exécution pour les allocations **statique**, **pile** (stack) et **dynamique** (heap)[cite: 15, 16].
* [cite_start]**Observation** : Analyse de l'impact des optimisations du compilateur sur la rapidité d'accès aux données[cite: 23, 24].

### 3. Liaison Statique vs Dynamique (C++)
* [cite_start]**Fichiers** : `programme3.cpp` & `programme4.cpp` [cite: 31, 54]
* [cite_start]**Concept** : Différence entre les méthodes classiques et les méthodes virtuelles[cite: 32, 56].
* [cite_start]**Observation** : Le programme 4 illustre l'utilisation d'une table virtuelle (VTable) à travers une hiérarchie de classes A → B → C[cite: 55, 62].

### 4. Gestion de la Concurrence (Java)
* [cite_start]**Fichier** : `programme5.java` [cite: 67]
* [cite_start]**Concept** : Modélisation du problème des **Lecteurs-Rédacteurs**[cite: 68].
* [cite_start]**Observation** : Utilisation du verrou `ReentrantReadWriteLock` pour permettre des lectures simultanées tout en garantissant l'exclusivité d'écriture[cite: 69, 70, 71].



## 📝 Rapport d'Analyse
[cite_start]Le document **Rapport.docx** fournit une discussion approfondie, les résultats de mesures chronométrées et les conclusions pour chaque problème traité[cite: 84, 87].

## 🛠️ Instructions d'Exécution

* [cite_start]**Perl** : `perl programme1.pl` [cite: 9]
* [cite_start]**C++** : `g++ programmeX.cpp -O2 -o progX` suivi de `./progX` [cite: 29, 30, 52, 53]
* [cite_start]**Java** : `javac programme5.java` suivi de `java programme5` [cite: 82, 83]

---
[cite_start]**Développeur : Wiston Fomene** [cite: 87]