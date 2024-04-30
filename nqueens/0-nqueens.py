#!/usr/bin/python3
"""_summary_

    Returns:
        _type_: _description_
"""

import sys


def safe_column_and_row(col, row, queen):
    """
    Vérifie si une reine peut être placée
    en toute sécurité sur une colonne et une ligne spécifiques.

    Args:
        col (int): La colonne à vérifier.
        row (int): La ligne à vérifier.
        queen (list): La configuration actuelle des reines.

    Returns:
        bool: True si la colonne et la ligne sont sûres, False sinon.
    """
    for i in range(row):
        if queen[i] == col:
            return False
    return True


def safe_diagonal(col, row, queen):
    """
    Vérifie si une reine peut être placée en
    toute sécurité sur une diagonale spécifique.

    Args:
        col (int): La colonne à vérifier.
        row (int): La ligne à vérifier.
        queen (list): La configuration actuelle des reines.

    Returns:
        bool: True si la diagonale est sûre, False sinon.
    """
    for i in range(row):
        if abs(queen[i] - col) == abs(i - row):
            return False
    return True


def nqueens(nQ, row, queen, solutions):
    """
    Résout le problème des N-Queens en utilisant la récursion.

    Args:
        nQ (int): Le nombre de reines à placer.
        row (int): La ligne actuelle.
        queen (list): La configuration actuelle des reines.
        solutions (list): La liste des solutions trouvées.

    Returns:
        None
    """
    if row == nQ:
        solutions.append([[i, queen[i]] for i in range(nQ)])
    else:
        for col in range(nQ):
            if safe_column_and_row(col,
                                   row,
                                   queen) and safe_diagonal(col, row, queen):
                queen[row] = col
                nqueens(nQ, row + 1, queen, solutions)


def main():
    """
    Fonction principale du programme.

    Args:
        None

    Returns:
        None
    """
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        nQ = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    if nQ < 4:
        print("N must be at least 4")
        sys.exit(1)
    queen = [0 for _ in range(nQ)]
    solutions = []
    nqueens(nQ, 0, queen, solutions)
    for solution in solutions:
        print(solution)


if __name__ == "__main__":
    main()
