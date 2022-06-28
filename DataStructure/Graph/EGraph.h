#pragma once

enum class EGraphType
{
    Matrix,
    List
};

template <EGraphType type, size_t N>
class MyGraph;

template <size_t N>
class MyGraph<EGraphType::Matrix, N>
{
public:
    // �� ������ �������� Ȯ���Ѵ�.
    bool        IsAdjacent(int start, int end);

    // ������ ���Ѵ�.
    int         GetDegree(int node);

    // ���� ������ ���Ѵ�.
    int         GetInDegree(int node);

    // ���� ������ ���Ѵ�.
    int         GetOutDegree(int node);

    // ������ �߰��Ѵ�.
    void        AddEdge(int start, int end, int weight = 1);

    // ������ �����Ѵ�.
    void        DeleteEdge(int start, int end);

    // ����Ѵ�.
    // ����..
    // [ 0 1 0 0 0 ]
    // [ 0 0 1 0 0 ]
    // [ 0 0 0 0 1 ]
    // [ 0 1 0 0 0 ]
    // [ 0 0 0 0 0 ]
    void        Print();

private:
    array<array<int, N>, N>     _edges;